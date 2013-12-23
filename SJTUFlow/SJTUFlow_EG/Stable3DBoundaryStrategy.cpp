//
//  Stable3DBoundaryStrategy.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#include "Stable3DBoundaryStrategy.h"
#include "Utility.h"

void Stable3DBoundaryStrategy::setBoundary( int N, BoundaryType type, float *value )
{
	int count_a;
	int count_b;

	for(count_a=1; count_a<=N; count_a++)
	{
		for(count_b=1; count_b<=N; count_b++)
		{
			if(type == BoundaryTypeU)
			{
				value[IX3D(0 ,count_a, count_b)]=-value[IX3D(1, count_a, count_b)];
				value[IX3D(N+1,count_a, count_b)]=-value[IX3D(N, count_a, count_b)];
			}
			else
			{
				value[IX3D(0 ,count_a, count_b)]=value[IX3D(1, count_a, count_b)];
				value[IX3D(N+1,count_a, count_b)]=value[IX3D(N, count_a, count_b)];
			}

			if(type == BoundaryTypeV)
			{
				value[IX3D(count_a, 0, count_b)]=-value[IX3D(count_a, 1, count_b)];
				value[IX3D(count_a, N+1, count_b)]=-value[IX3D(count_a, N, count_b)];
			}
			else
			{
				value[IX3D(count_a, 0, count_b)]=value[IX3D(count_a, 1, count_b)];
				value[IX3D(count_a, N+1, count_b)]=value[IX3D(count_a, N, count_b)];
			}

			if(type == BoundaryTypeW)
			{
				value[IX3D(count_a, count_b, 0)]=-value[IX3D(count_a, count_b, 1)];
				value[IX3D(count_a, count_b, N+1)]=-value[IX3D(count_a, count_b, N)];
			}
			else
			{
				value[IX3D(count_a, count_b, 0)]=value[IX3D(count_a, count_b, 1)];
				value[IX3D(count_a, count_b, N+1)]=value[IX3D(count_a, count_b, N)];
			}
		}
	}

	value[IX3D(0, 0, 0)]=(float)(1.0/3.0*(value[IX3D(1, 0, 0)]+value[IX3D(0, 1, 0)]+value[IX3D(0, 0, 1)]));
	value[IX3D(0, N+1, 0)]=(float)(1.0/3.0*(value[IX3D(1, N+1, 0)]+value[IX3D(0, N, 0)]+value[IX3D(0, N+1, 1)]));

	value[IX3D(N+1, 0, 0)]=(float)(1.0/3.0*(value[IX3D(N, 0, 0)]+value[IX3D(N+1, 1, 0)]+value[IX3D(N+1, 0, 1)]));
	value[IX3D(N+1, N+1, 0)]=(float)(1.0/3.0*(value[IX3D(N, N+1, 0)]+value[IX3D(N+1, N, 0)]+value[IX3D(N+1, N+1, 1)]));

	value[IX3D(0, 0, N+1)]=(float)(1.0/3.0*(value[IX3D(1, 0, N+1)]+value[IX3D(0, 1, N+1)]+value[IX3D(0, 0, N)]));
	value[IX3D(0, N+1, N+1)]=(float)(1.0/3.0*(value[IX3D(1, N+1, N+1)]+value[IX3D(0, N, N+1)]+value[IX3D(0, N+1, N)]));

	value[IX3D(N+1, 0, N+1)]=(float)(1.0/3.0*(value[IX3D(N, 0, N+1)]+value[IX3D(N+1, 1, N+1)]+value[IX3D(N+1, 0,N)]));
	value[IX3D(N+1, N+1,N+1)]=(float)(1.0/3.0*(value[IX3D(N, N+1, N+1)]+value[IX3D(N+1, N, N+1)]+value[IX3D(N+1, N+1, N)]));
}

BoundaryStrategy * Stable3DBoundaryStrategy::Create()
{
	return new Stable3DBoundaryStrategy;
}

void Stable3DBoundaryStrategy::ExportClass()
{
	class_<Stable3DBoundaryStrategy, bases<BoundaryStrategy>>("Stable3DBoundaryStrategy", init<>())
		.def("setBoundary", &Stable3DBoundaryStrategy::setBoundary)
		.def("Create", &Stable3DBoundaryStrategy::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
