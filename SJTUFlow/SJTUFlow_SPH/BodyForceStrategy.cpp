/***********************************************************************
 * Module:  BodyForceStrategy.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class BodyForceStrategy
 ***********************************************************************/

#include "BodyForceStrategy.h"

void BodyForceStrategyWrap::ApplyBodyForce( int particleNum, float kDt, Particle* particles )
{
	this->get_override("ApplyBodyForce")(particleNum, kDt, particles);
}

void BodyForceStrategyWrap::ExportClass()
{
	class_<BodyForceStrategyWrap, boost::noncopyable>("BodyForceStrategy")
		.def("ApplyBodyForce", pure_virtual(&BodyForceStrategy::ApplyBodyForce));
}
