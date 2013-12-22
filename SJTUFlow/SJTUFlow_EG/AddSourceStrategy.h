//
//  AddSourceStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-19.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_AddSourceStrategy_h
#define Eulter_SE_AddSourceStrategy_h

#include "boost/python.hpp"
using namespace boost::python;


class AddSourceStrategy
{
public:
    virtual void addSource(int N, float * x, float * s, float dt) = 0;
};

class AddSourceStrategyWrap : public AddSourceStrategy, public wrapper<AddSourceStrategy>
{
public:
	void addSource(int N, float * x, float * s, float dt)
	{
		this->get_override("addSource")(N, x, s, dt);
	}

	static void ExportClass()
	{
		class_<AddSourceStrategyWrap, boost::noncopyable>("AddSourceStrategy")
			.def("addSource", pure_virtual(&AddSourceStrategy::addSource));
	}
};

#endif
