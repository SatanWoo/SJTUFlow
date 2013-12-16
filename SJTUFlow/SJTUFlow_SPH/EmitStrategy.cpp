/***********************************************************************
 * Module:  EmitStrategy.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:54
 * Purpose: Implementation of the class EmitStrategy
 ***********************************************************************/

#include "EmitStrategy.h"

size_t EmitStrategyWrap::EmitParticles( int particleNum, float kDt, Particle* particles )
{
	return this->get_override("EmitParticles")(particleNum, kDt, particles);
}

void EmitStrategyWrap::ExportClass()
{
	class_<EmitStrategyWrap, boost::noncopyable>("EmitStrategy")
		.def("EmitParticles", pure_virtual(&EmitStrategy::EmitParticles));
}
