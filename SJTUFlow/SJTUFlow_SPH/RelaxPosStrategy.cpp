/***********************************************************************
 * Module:  RelaxPosStrategy.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:08
 * Purpose: Implementation of the class RelaxPosStrategy
 ***********************************************************************/

#include "RelaxPosStrategy.h"

void RelaxPosStrategyWrap::RelaxPos( int particleNum, float kDt, Particle* particles )
{
	this->get_override("RelaxPos")(particleNum, kDt, particles);
}

void RelaxPosStrategyWrap::ExportClass()
{
	class_<RelaxPosStrategyWrap, boost::noncopyable>("RelaxPosStrategy")
		.def("RelaxPos", pure_virtual(&RelaxPosStrategy::RelaxPos));
}
