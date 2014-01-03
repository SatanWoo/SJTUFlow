//
//  Stable2DAddSourceStrategy.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-19.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#include "Stable2DAddSourceStrategy.h"

void Stable2DAddSourceStrategy::addSource(int N, float * x, float * s, float dt)
{
    int i, size = (N+2)*(N+2);
	for ( i = 0 ; i < size ; i++) x[i] += dt*s[i];
}

AddSourceStrategy * Stable2DAddSourceStrategy::Create()
{
	return new Stable2DAddSourceStrategy;
}

void Stable2DAddSourceStrategy::ExportClass()
{
	class_<Stable2DAddSourceStrategy, bases<AddSourceStrategy>>("Stable2DAddSourceStrategy", init<>())
		.def("addSource", &Stable2DAddSourceStrategy::addSource)
		.def("Create", &Stable2DAddSourceStrategy::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
