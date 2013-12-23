//
//  EulerGrid2D.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-15.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#include "EulerGrid.h"
#include "Utility.h"

#include "boost/python.hpp"
using namespace boost::python;

EulerGrid2D::EulerGrid2D(int size, float viscocity, float time)
	:m_size(size), m_viscocity(viscocity), m_time(time)
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

EulerGrid3D::EulerGrid3D( int size, float viscocity, float time )
	:m_size(size), m_viscocity(viscocity), m_time(time)
{
	u = new Velocity3D(size);
	v = new Velocity3D(size);
	w = new Velocity3D(size);
	density = new Velocity3D(size);
}

EulerGrid3D::~EulerGrid3D()
{
	if (u) delete u;
	if (v) delete v;
	if (w) delete w;
	if (density) delete density;
}

void EulerGrid3D::ExportClass()
{
	class_<EulerGrid3D>("EulerGrid3D", init<int, float, float>())
		.def("getCurU", &EulerGrid3D::getCurU)
		.def("getCurV", &EulerGrid3D::getCurV)
		.def("getCurW", &EulerGrid3D::getCurW)
		.def("getCurDensity", &EulerGrid3D::getCurDensity)
		.def("getPreU", &EulerGrid3D::getPreU)
		.def("getPreV", &EulerGrid3D::getPreV)
		.def("getPreW", &EulerGrid3D::getPreW)
		.def("getPreDensity", &EulerGrid3D::getPreDensity)
		.def("setCurU", &EulerGrid3D::setCurU)
		.def("setCurV", &EulerGrid3D::setCurV)
		.def("setCurW", &EulerGrid3D::setCurW)
		.def("setCurDensity", &EulerGrid3D::setCurDensity)
		.def("setPreU", &EulerGrid3D::setPreU)
		.def("setPreV", &EulerGrid3D::setPreV)
		.def("setPreW", &EulerGrid3D::setPreW)
		.def("setPreDensity", &EulerGrid3D::setPreDensity);
}
