//
//  AddSourceStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-19.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#ifndef _PROJECTSTRATEGY_H
#define _PROJECTSTRATEGY_H

#include "BoundaryStrategy.h"

#include "boost/python.hpp"
using namespace boost::python;

class ProjectStrategy
{
public:
	virtual void project(int N, float * u, float * v, float * p, float * div) = 0;
	virtual void project3D(int N, float * u, float * v, float * w, float * p, float * div) = 0;
protected:
	BoundaryStrategy *m_bs;
};

class ProjectStrategyWrap : public ProjectStrategy, public wrapper<ProjectStrategy>
{
public:
	void project(int N, float * u, float * v, float * p, float * div)
	{
		this->get_override("project")(N, u, v, p, div);
	}
	void project3D(int N, float * u, float * v, float * w, float * p, float * div)
	{
		this->get_override("project3D")(N, u, v, w, p, div);
	}

	static void ExportClass()
	{
		class_<ProjectStrategyWrap, boost::noncopyable>("ProjectStrategy")
			.def("project", pure_virtual(&ProjectStrategy::project))
			.def("project3D", pure_virtual(&ProjectStrategy::project3D));
	}
};

#endif