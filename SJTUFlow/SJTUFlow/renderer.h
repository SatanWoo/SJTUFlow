#ifndef RENDERER_H
#define RENDERER_H

class Renderer
{
public:
	Renderer();
	~Renderer();

	static void RenderEuler3D(float* d, int N, int frame, 
		const char* filename, int width, int height);

private:
	static void WriteBmp(const char* filename, 
		unsigned char* image, int width, int height, bool invertY);
};

#endif // RENDERER_H
