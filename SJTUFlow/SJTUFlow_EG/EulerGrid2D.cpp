//
//  EulerGrid2D.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-15.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#include "EulerGrid2D.h"
#include "Utility.h"

#include "boost/python.hpp"
using namespace boost::python;

EulerGrid2D::EulerGrid2D(int size, float viscocity, float time):m_size(size), m_viscocity(viscocity), m_time(time)
{
    u = new Velocity2D(size);
    v = new Velocity2D(size);
    density = new Velocity2D(size);
}

EulerGrid2D::~EulerGrid2D()
{
    if (u) delete u;
    if (v) delete v;
    if (density) delete density;
}

void EulerGrid2D::ExportClass()
{
	class_<EulerGrid2D>("EulerGrid2D", init<int, float, float>())
		.def("getCurU", &EulerGrid2D::getCurU)
		.def("getCurV", &EulerGrid2D::getCurV)
		.def("getCurDensity", &EulerGrid2D::getCurDensity)
		.def("getPreU", &EulerGrid2D::getPreU)
		.def("getPreV", &EulerGrid2D::getPreV)
		.def("getPreDensity", &EulerGrid2D::getPreDensity)
		.def("setCurU", &EulerGrid2D::setCurU)
		.def("setCurV", &EulerGrid2D::setCurV)
		.def("setCurDensity", &EulerGrid2D::setCurDensity)
		.def("setPreU", &EulerGrid2D::setPreU)
		.def("setPreV", &EulerGrid2D::setPreV)
		.def("setPreDensity", &EulerGrid2D::setPreDensity);
}
