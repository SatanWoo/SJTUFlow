//
//  AddSourceStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-19.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#ifndef _AddSourceStrategy_h
#define _AddSourceStrategy_h

#include "boost/python.hpp"
using namespace boost::python;

class AddSourceStrategy
{
public:
	virtual void addSource(int N, float *value, float *value_prev, float dt) = 0;
};

class AddSourceStrategyWrap : public AddSourceStrategy, public wrapper<AddSourceStrategy>
{
public:
	void addSource(int N, float *value, float *value_prev, float dt)
	{
		this->get_override("addSource")(N, value, value_prev, dt);
	}

	static void ExportClass()
	{
		class_<AddSourceStrategyWrap, boost::noncopyable>("AddSourceStrategy")
			.def("addSource", pure_virtual(&AddSourceStrategy::addSource));
	}
};

#endif