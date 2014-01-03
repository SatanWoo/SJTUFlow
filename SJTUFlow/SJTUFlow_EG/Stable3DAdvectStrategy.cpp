//
//  Stable3DAdvectStrategy.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#include "Stable3DAdvectStrategy.h"
#include "Utility.h"

void Stable3DAdvectStrategy::advect3D( int N, BoundaryType b, float *density, float *density_prev, float *velocity_u, float *velocity_v, float *velocity_w, float dt )
{
	int count_x;
	int count_y;
	int count_z;

	int i0;
	int j0;
	int k0;

	int i1;
	int j1;
	int k1;

	float x;
	float y;
	float z;

	float s0;
	float t0;
	float s1;
	float t1;
	float u1;
	float u0;

	float dh;

	dh=dt*N;

	for(count_x=1; count_x<=N; count_x++)
	{
		for(count_y=1; count_y<=N; count_y++)
		{
			for(count_z=1; count_z<=N; count_z++)
			{
				x=count_x-dh*velocity_u[IX3D(count_x, count_y, count_z)];
				y=count_y-dh*velocity_v[IX3D(count_x, count_y, count_z)];
				z=count_z-dh*velocity_w[IX3D(count_x, count_y, count_z)];

				if(x < 0.5)
				{
					x=0.5;
				}

				if(x > N+0.5)
				{
					x=(float)(N+0.5);
				}

				if(y < 0.5)
				{
					y=0.5;
				}

				if(y > N+0.5)
				{
					y=(float)(N+0.5);
				}

				if(z<0.5)
				{
					z=0.5;
				}

				if(z>N+0.5)
				{
					z=(float)(N+0.5);
				}

				i0=(int)x;
				i1=i0+1;
				j0=(int)y;
				j1=j0+1;
				k0=(int)z;
				k1=k0+1;

				s1=x-i0;
				s0=1-s1;
				t1=y-j0;
				t0=1-t1;
				u1=z-k0;
				u0=1-u1;

				density[IX3D(count_x, count_y, count_z)]=s0*(t0*u0*density_prev[IX3D(i0,j0,k0)]+t1*u0*density_prev[IX3D(i0,j1,k0)]+t0*u1*density_prev[IX3D(i0,j0,k1)]+t1*u1*density_prev[IX3D(i0,j1,k1)])+s1*(t0*u0*density_prev[IX3D(i1,j0,k0)]+t1*u0*density_prev[IX3D(i1,j1,k0)]+t0*u1*density_prev[IX3D(i1,j0,k1)]+t1*u1*density_prev[IX3D(i1,j1,k1)]);
			}
		}
	}
}

AdvectStrategy * Stable3DAdvectStrategy::Create()
{
	return new Stable3DAdvectStrategy;
}

void Stable3DAdvectStrategy::ExportClass()
{
	class_<Stable3DAdvectStrategy, bases<AdvectStrategy>>("Stable3DAdvectStrategy", init<>())
		.def("advect3D", &Stable3DAdvectStrategy::advect3D)
		.def("Create", &Stable3DAdvectStrategy::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
