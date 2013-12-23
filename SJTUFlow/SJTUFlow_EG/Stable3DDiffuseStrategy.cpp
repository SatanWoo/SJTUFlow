//
//  Stable3DDiffuseStrategy.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#include "Stable3DDiffuseStrategy.h"
#include "MathHelper.h"

void Stable3DDiffuseStrategy::diffuse( int N, BoundaryType b, float *value, float *value_prev, float diff, float dt )
{
	float alpha = dt * diff * N * N * N;
	MathHelper::linearCalculation3D(N, b, value, value_prev, alpha, 1+6*alpha);
}

DiffuseStrategy * Stable3DDiffuseStrategy::Create()
{
	return new Stable3DDiffuseStrategy;
}

void Stable3DDiffuseStrategy::ExportClass()
{
	class_<Stable3DDiffuseStrategy, bases<DiffuseStrategy>>("Stable3DDiffuseStrategy", init<>())
		.def("diffuse", &Stable3DDiffuseStrategy::diffuse)
		.def("Create", &Stable3DDiffuseStrategy::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
