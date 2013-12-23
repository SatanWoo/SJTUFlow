//
//  Stable3DProjectStrategy.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#include "Stable3DProjectStrategy.h"
#include "Utility.h"
#include "MathHelper.h"

Stable3DProjectStrategy::Stable3DProjectStrategy( BoundaryStrategy *bs )
{
	m_bs = bs;
}

void Stable3DProjectStrategy::project( int N, float *velocity_u, float *velocity_v, float *velocity_w, float *p, float *div )
{
	int count_x;
	int count_y;
	int count_z;

	for(count_x=1; count_x<=N; count_x++)
	{
		for(count_y=1; count_y<=N; count_y++)
		{
			for(count_z=1; count_z<=N; count_z++)
			{
				div[IX3D(count_x, count_y, count_z)]=(float)(-1.0/3.0*((velocity_u[IX3D(count_x+1, count_y, count_z)]-velocity_u[IX3D(count_x-1, count_y, count_z)])/N+(velocity_v[IX3D(count_x, count_y+1, count_z)]-velocity_v[IX3D(count_x, count_y-1, count_z)])/N+(velocity_w[IX3D(count_x, count_y, count_z+1)]-velocity_w[IX3D(count_x, count_y, count_z-1)])/N));
				p[IX3D(count_x, count_y, count_z)] = 0;
			}
		}
	}

	m_bs->setBoundary(N, BoundaryTypeNone, div);
	m_bs->setBoundary(N, BoundaryTypeNone,  p);

	MathHelper::linearCalculation3D(N, BoundaryTypeNone, p, div, 1, 6);

	for(count_x=1; count_x<=N; count_x++)
	{
		for(count_y=1; count_y<=N; count_y++)
		{
			for(count_z=1; count_z<=N; count_z++)
			{
				velocity_u[IX3D(count_x, count_y, count_z)] -= 0.5f*N*(p[IX3D(count_x+1, count_y, count_z)]-p[IX3D(count_x-1, count_y, count_z)]);
				velocity_v[IX3D(count_x, count_y, count_z)] -= 0.5f*N*(p[IX3D(count_x, count_y+1, count_z)]-p[IX3D(count_x, count_y-1, count_z)]);
				velocity_w[IX3D(count_x, count_y, count_z)] -= 0.5f*N*(p[IX3D(count_x, count_y, count_z+1)]-p[IX3D(count_x, count_y, count_z-1)]);
			}
		}
	}

	m_bs->setBoundary(N, BoundaryTypeU, velocity_u);
	m_bs->setBoundary(N, BoundaryTypeV, velocity_v);
	m_bs->setBoundary(N, BoundaryTypeW, velocity_w);
}

Project3DStrategy * Stable3DProjectStrategy::Create( BoundaryStrategy *bs )
{
	return new Stable3DProjectStrategy(bs);
}

void Stable3DProjectStrategy::ExportClass()
{
	class_<Stable3DProjectStrategy, bases<Project3DStrategy>>("Stable3DProjectStrategy", init<>())
		.def("project", &Stable3DProjectStrategy::project)
		.def("Create", &Stable3DProjectStrategy::Create, 
		return_value_policy<manage_new_object>(), with_custodian_and_ward<1, 2>())
		.staticmethod("Create");
}
