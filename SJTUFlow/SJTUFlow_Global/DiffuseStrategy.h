//
//  AddSourceStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-19.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#ifndef _DIFFUSESTRATEGY_H
#define _DIFFUSESTRATEGY_H

#include "BoundaryStrategy.h"

#include "boost/python.hpp"
using namespace boost::python;

class DiffuseStrategy
{
public:
	virtual void diffuse(int N, BoundaryType b, float * x, float * x0, float diff, float dt) = 0;
};

class DiffuseStrategyWrap : public DiffuseStrategy, public wrapper<DiffuseStrategy>
{
public:
	void diffuse(int N, BoundaryType b, float * x, float * x0, float diff, float dt)
	{
		this->get_override("diffuse")(N, b, x, x0, diff, dt);
	}

	static void ExportClass()
	{
		class_<DiffuseStrategyWrap, boost::noncopyable>("DiffuseStrategy")
			.def("diffuse", pure_virtual(&DiffuseStrategy::diffuse));
	}
};

#endif