/***********************************************************************
 * Module:  RenderSPHStrategy.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:28
 * Purpose: Implementation of the class RenderSPHStrategy
 ***********************************************************************/

#include "RenderSPHStrategy.h"

void RenderSPHStrategyWrap::RenderInit()
{
	this->get_override("RenderInit")();
}

void RenderSPHStrategyWrap::RenderSPH( int particleNum, Particle* particles, std::string scene )
{
	this->get_override("RenderSPH")(particleNum, particles, scene);
}

void RenderSPHStrategyWrap::ExportClass()
{
	class_<RenderSPHStrategyWrap, boost::noncopyable>("RenderSPHStrategy")
		.def("RenderInit", pure_virtual(&RenderSPHStrategy::RenderInit))
		.def("RenderSPH", pure_virtual(&RenderSPHStrategy::RenderSPH));
}
