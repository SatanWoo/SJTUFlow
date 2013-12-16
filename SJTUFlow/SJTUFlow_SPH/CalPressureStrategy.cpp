/***********************************************************************
 * Module:  CalPressureStrategy.cpp
 * Author:  zs
 * Modified: 2013��11��21�� 20:26:15
 * Purpose: Implementation of the class CalPressureStrategy
 ***********************************************************************/

#include "CalPressureStrategy.h"

void CalPressureStrategyWrap::CalPressure( int particleNum, Particle* particles )
{
	this->get_override("CalPressure")(particleNum, particles);
}

void CalPressureStrategyWrap::ExportClass()
{
	class_<CalPressureStrategyWrap, boost::noncopyable>("CalPressureStrategy")
		.def("CalPressure", pure_virtual(&CalPressureStrategy::CalPressure));
}
