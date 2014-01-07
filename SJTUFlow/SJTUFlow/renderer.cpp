#include "renderer.h"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define min(x,y) (x) < (y) ? (x) : (y)
#define max(x,y) (x) > (y) ? (x) : (y)

struct header
{
	char bfType[3];
	int bfSize;
	int bfReserved;
	int bfOffBits;

	int biSize;
	int biWidth;
	int biHeight;
	short biPlanes;
	short biBitCount;
	int biCompression;
	int biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	int biClrUsed;

	int biClrImportant;
};

template <class T>
static void my_fwrite( T *data, size_t size, size_t n, FILE * fp )
{
	int x=1; // 0x00000001
	if (*(char*)&x)
	{
		// Little Endian
		fwrite( data, size, n, fp );
	}
	else
	{
		//Big Endian
		T value = *data;
		for( int i=0; i<size; i++ )
		{
			int v = (value >> (8*i)) & 0x000000ff;
			putc(v, fp);
		}
	}
}

static void normalize( float v[3] ) {
	float len = hypotf(v[0], hypotf(v[1], v[2]));
	if( len ) {
		v[0] /= len;
		v[1] /= len;
		v[2] /= len;
	}
}

static float interp( float* d, int width, int height, int depth, float x, float y, float z )
{
	int i0, j0, k0, i1, j1, k1;
	float s0, t0, w0, s1, t1, w1;

	if (x<0.0) x=0.0; if (x>width) x=width; i0=min(width-2,(int)x); i1=i0+1;
	if (y<0.0) y=0.0; if (y>height) y=height; j0=min(height-2,(int)y); j1=j0+1;
	if (z<0.0) z=0.0; if (z>depth) z=depth; k0=min(depth-2,(int)z); k1=k0+1;

	s1 = x-i0; s0 = 1-s1; t1 = y-j0; t0 = 1-t1; w1 = z-k0; w0 = 1-w1;

	return		w0*(s0*(t0*d[i0*height*depth+j0*depth+k0]+t1*d[i0*height*depth+j1*depth+k0])+
		s1*(t0*d[i1*height*depth+j0*depth+k0]+t1*d[i1*height*depth+j1*depth+k0])) +
		w1*(s0*(t0*d[i0*height*depth+j0*depth+k1]+t1*d[i0*height*depth+j1*depth+k1])+
		s1*(t0*d[i1*height*depth+j0*depth+k1]+t1*d[i1*height*depth+j1*depth+k1]));
}

static double sample3D( float *d, int N, float p[3] ) {
	if( p[0] < 0.0 || p[0] > 1.0 || 
		p[1] < 0.0 || p[1] > 1.0 ||
		p[2] < 0.0 || p[2] > 1.0 ) return 0.0;

	return interp( d, N, N, N, N*p[0], N*p[1], N*p[2] );
}

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::RenderEuler3D( float* d, int N, int frame, 
	const char* filename, int width, int height )
{
	// Eye Position
	const float eyePos[3] = { 0.5, 0.5, -1.0 };

	// Light Position
	const float lightPos[3] = { 0.5, 1.5, 0.2 };

	// Light Intensity
	const float lightIntensity = 8.0;

	// Absortion
	const float absorption = 11.0;

	// Ray Samples
	const int numSamples = 128;

	// Ray Light Samples
	const int numLightSample = 64;

	// Maximum Distance
	const float maxDist = 3.0;

	// Ray Sampling Space
	const float stride = maxDist/numSamples;

	// Light Ray Sampling Space
	const float lstride = maxDist/numLightSample;

	// Memory Allocation
	static unsigned char *image = new unsigned char[width*height*4];

	for( int ci=0; ci<width*height; ci++ ) { 
		int i=ci%width; int j=ci/width;
		// Transmittance
		float T = 1.0;

		// In-scattered Radiance
		float Lo = 0.0;

		// Pixel Position
		float pixPos[3] = {i/(float)width,j/(float)height};

		// Eye Vector
		float eyeVec[3] = {pixPos[0]-eyePos[0],pixPos[1]-eyePos[1],pixPos[2]-eyePos[2]};
		normalize(eyeVec);

		// Sphere Hit
		bool hitSphere = false;
		float dotProduct = 0.0;

		// Sample Density...
		for( int n=0; n<numSamples; n++ ) {

			// Sample Point
			float pos[3] = { eyePos[0]+stride*n*eyeVec[0], eyePos[1]+stride*n*eyeVec[1], eyePos[2]+stride*n*eyeVec[2] };

			// Sample Density
			float density = sample3D(d, N, pos);

			// Skip Empty Density
			if( density > 0.0 ) {

				// Attenuate
				T *= 1.0-density*stride*absorption;
				if( T <= 0.01 ) break;

				// Compute Light Ray
				float lightVec[3] = {lightPos[0]-pos[0],lightPos[1]-pos[1],lightPos[2]-pos[2]};
				normalize(lightVec);

				// Transmittance Along Light Ray
				float Tl = 1.0;

				// Sample Density Again...
				for( int m=1; m<numLightSample; m++ ) {

					// Sample Point
					float lpos[3] = { pos[0]+lstride*m*lightVec[0], pos[1]+lstride*m*lightVec[1], pos[2]+lstride*m*lightVec[2] };

					// Sample Density
					float ldensity = sample3D(d, N, lpos);

					// Attenuate
					Tl *= 1.0-absorption*lstride*ldensity;
					if( Tl <= 0.01 ) break;
				}

				float Li = lightIntensity*Tl;
				Lo += Li*T*density*stride;
			}
		}

		// At Floor
		float Tf = 0.0;
		if( eyeVec[1] < 0.0 && hitSphere == false ) {
			float flen = -pixPos[1]/eyeVec[1];
			Tf = exp(-0.3*flen);

			// Compute Floor Intersection
			float pos[3] = {pixPos[0]+flen*eyeVec[0],pixPos[1]+flen*eyeVec[1],pixPos[2]+flen*eyeVec[2]};

			// Compute Light Ray
			float lightVec[3] = {lightPos[0]-pos[0],lightPos[1]-pos[1],lightPos[2]-pos[2]};
			normalize(lightVec);

			// Sample Density
			for( int m=1; m<numLightSample; m++ ) {

				// Sample Point
				float lpos[3] = { pos[0]+lstride*m*lightVec[0], pos[1]+lstride*m*lightVec[1], pos[2]+lstride*m*lightVec[2] };

				// Sample Density
				float ldensity = sample3D(d, N, lpos);

				// Attenuate
				Tf *= 1.0-0.5*absorption*lstride*ldensity;
				if( Tf <= 0.01 ) break;
			}
		}

		// Floor Color
		unsigned char floor_color[3] = { 75, 60, 45 };

		// Sphere Color
		unsigned char sphere_color[3] = { 50, 100, 150 };

		for( int k=0; k<3; k++ ) {
			image[4*(i+j*width)+k] = max(0,min(255,255*Lo + T*(Tf*floor_color[k] + dotProduct*sphere_color[k])));
		}
	}

	char fn[128];
	sprintf(fn, "%s_%d.bmp", filename, frame );
	WriteBmp(fn, image, width, height, false );
}

void Renderer::WriteBmp( const char* filename, 
	unsigned char* image, int width, int height, bool invertY )
{
	int bytesPerLine;
	unsigned char *lines;

	FILE *fp;
	header bmph;

	bytesPerLine = (3 * (width + 1) / 4) * 4;

	strcpy(bmph.bfType, "BM");
	bmph.bfOffBits = 54;
	bmph.bfSize = bmph.bfOffBits + bytesPerLine * height;
	bmph.bfReserved = 0;
	bmph.biSize = 40;
	bmph.biWidth = width;
	bmph.biHeight = height;
	bmph.biPlanes = 1;
	bmph.biBitCount = 24;
	bmph.biCompression = 0;
	bmph.biSizeImage = bytesPerLine * height;
	bmph.biXPelsPerMeter = 0;
	bmph.biYPelsPerMeter = 0;
	bmph.biClrUsed = 0;
	bmph.biClrImportant = 0;

	fp = fopen (filename, "wb");
	if (! fp ) return;

	fwrite(bmph.bfType, 2, 1, fp );
	my_fwrite<int>(&bmph.bfSize, 4, 1, fp );
	my_fwrite<int>(&bmph.bfReserved, 4, 1, fp );
	my_fwrite<int>(&bmph.bfOffBits, 4, 1, fp );
	my_fwrite<int>(&bmph.biSize, 4, 1, fp ) ;
	my_fwrite<int>(&bmph.biWidth, 4, 1, fp );
	my_fwrite<int>(&bmph.biHeight, 4, 1, fp );
	my_fwrite<short>(&bmph.biPlanes, 2, 1, fp );
	my_fwrite<short>(&bmph.biBitCount, 2, 1, fp );
	my_fwrite<int>(&bmph.biCompression, 4, 1, fp );
	my_fwrite<int>(&bmph.biSizeImage, 4, 1, fp );
	my_fwrite<int>(&bmph.biXPelsPerMeter, 4, 1, fp );
	my_fwrite<int>(&bmph.biYPelsPerMeter, 4, 1, fp );
	my_fwrite<int>(&bmph.biClrUsed, 4, 1, fp );
	my_fwrite<int>(&bmph.biClrImportant, 4, 1, fp );

	lines = (unsigned char *)malloc(bytesPerLine * height);
	for ( int v=0; v < height; v++ )
	{
		int i;
		if( invertY ) i = v;
		else i = height - v - 1;

		for ( int j = 0; j < width; j++)
		{
			int pos = 4 * (width * i + j);
			lines[3*j+i*bytesPerLine] = image[pos + 2];
			lines[3*j+i*bytesPerLine+1] = image[pos + 1];
			lines[3*j+i*bytesPerLine+2] = image[pos];
		}
	}
	fwrite(lines, bytesPerLine * height, 1, fp );

	free(lines);
	fclose(fp);
}
