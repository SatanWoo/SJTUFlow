//
//  AddSourceStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-19.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#ifndef _ADVECTSTRATEGY_H
#define _ADVECTSTRATEGY_H

#include "BoundaryStrategy.h"

class AdvectStrategy
{
public:
	virtual void advect(int N, BoundaryType type, float *density, float *preDensity, float *u, float *v, float dt) = 0;
	virtual void advect3D(int N, BoundaryType type, float *density, float *preDensity, float *u, float *v, float *w, float dt) = 0;
};

class AdvectStrategyWrap : public AdvectStrategy, public wrapper<AdvectStrategy>
{
public:
	void advect(int N, BoundaryType type, float *density, float *preDensity, float *u, float *v, float dt)
	{
		this->get_override("advect")(N, type, density, preDensity, u, v, dt);
	}
	void advect3D(int N, BoundaryType type, float *density, float *preDensity, float *u, float *v, float *w, float dt)
	{
		this->get_override("advect3D")(N, type, density, preDensity, u, v, w, dt);
	}

	static void ExportClass()
	{
		class_<AdvectStrategyWrap, boost::noncopyable>("AdvectStrategy")
			.def("advect", pure_virtual(&AdvectStrategy::advect))
			.def("advect3D", pure_virtual(&AdvectStrategy::advect3D));
	}
};

#endif