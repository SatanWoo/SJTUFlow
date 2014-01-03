/***********************************************************************
 * Module:  BodyForceStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class BodyForceStrategy
 ***********************************************************************/
#ifndef _BODYFORCESTRATEGY_H
#define _BODYFORCESTRATEGY_H

#include "AbstractParticle.h"

#include <boost/python.hpp>
using namespace boost::python;

class BodyForceStrategy
{
public:
	////////////////////////////////////////////////////////////////////////
	// Name:       BodyForceStrategy::ApplyBodyForce(int particleNum, float kDt, AbstractParticle** particles)
	// Purpose:    Implementation of BodyForceStrategy::ApplyBodyForce()
	// Parameters:
	// - particleNum
	// - kDt
	// - particles
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void ApplyBodyForce(int particleNum, float kDt, AbstractParticle** particles) = 0;
};

class BodyForceStrategyWrap : public BodyForceStrategy, public wrapper<BodyForceStrategy>
{
public:
	void ApplyBodyForce(int particleNum, float kDt, AbstractParticle** particles)
	{
		this->get_override("ApplyBodyForce")(particleNum, kDt, particles);
	}

	static void ExportClass()
	{
		class_<BodyForceStrategyWrap, boost::noncopyable>("BodyForceStrategy")
			.def("ApplyBodyForce", pure_virtual(&BodyForceStrategy::ApplyBodyForce));
	}
};

#endif