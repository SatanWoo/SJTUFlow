/***********************************************************************
 * Module:  EmitStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:54
 * Purpose: Declaration of the class EmitStrategy
 ***********************************************************************/
#ifndef _EMITSTRATEGY_H
#define _EMITSTRATEGY_H

#include "AbstractParticle.h"

#include <boost/python.hpp>
using namespace boost::python;

class EmitStrategy
{
public:
	////////////////////////////////////////////////////////////////////////
	// Name:       EmitStrategy::EmitParticles(int particleNum, float kDt, AbstractParticle** particles)
	// Purpose:    Implementation of EmitStrategy::EmitParticles()
	// Parameters:
	// - particleNum
	// - kDt
	// - particles
	// Return:     size_t
	////////////////////////////////////////////////////////////////////////
	virtual size_t EmitParticles(int particleNum, float kDt, AbstractParticle** particles) = 0;
};

class EmitStrategyWrap : public EmitStrategy, public wrapper<EmitStrategy>
{
public:
	size_t EmitParticles(int particleNum, float kDt, AbstractParticle** particles)
	{
		return this->get_override("EmitParticles")(particleNum, kDt, particles);
	}

	static void ExportClass()
	{
		class_<EmitStrategyWrap, boost::noncopyable>("EmitStrategy")
			.def("EmitParticles", pure_virtual(&EmitStrategy::EmitParticles));
	}
};

#endif