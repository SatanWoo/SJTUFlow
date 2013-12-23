//
//  Stable3DAddSourceStrategy.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#include "Stable3DAddSourceStrategy.h"

void Stable3DAddSourceStrategy::addSource(int N, float *value, float *value_prev, float dt)
{
    int size = (N + 2) * (N + 2) * (N + 2);
    
    for(int count = 0; count < size; count++)
    {
        value[count] = value[count]+ dt * value_prev[count];
    }
}

AddSourceStrategy * Stable3DAddSourceStrategy::Create()
{
	return new Stable3DAddSourceStrategy;
}

void Stable3DAddSourceStrategy::ExportClass()
{
	class_<Stable3DAddSourceStrategy, bases<AddSourceStrategy>>("Stable3DAddSourceStrategy", init<>())
		.def("addSource", &Stable3DAddSourceStrategy::addSource)
		.def("Create", &Stable3DAddSourceStrategy::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
