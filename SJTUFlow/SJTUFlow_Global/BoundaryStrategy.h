//
//  AddSourceStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-19.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#ifndef _BOUNDARYSTRATEGY_H
#define _BOUNDARYSTRATEGY_H

typedef enum
{
	BoundaryTypeNone = 0,
	BoundaryTypeU = 1,
	BoundaryTypeV = 2,
	BoundaryTypeW = 3
}BoundaryType;

#include "boost/python.hpp"
using namespace boost::python;

class BoundaryStrategy
{
public:
	virtual void setBoundary(int size, BoundaryType type, float *boundary) = 0;
};

class BoundaryStrategyWrap : public BoundaryStrategy, public wrapper<BoundaryStrategy>
{
public:
	void setBoundary(int size, BoundaryType type, float *boundary)
	{
		this->get_override("setBoundary")(size, type, boundary);
	}

	static void ExportClass()
	{
		class_<BoundaryStrategyWrap, boost::noncopyable>("BoundaryStrategy")
			.def("setBoundary", pure_virtual(&BoundaryStrategy::setBoundary));
	}
};

#endif