/***********************************************************************
 * Module:  RelaxPosStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:08
 * Purpose: Declaration of the class RelaxPosStrategy
 ***********************************************************************/
#ifndef _RELAXPOSSTRATEGY_H
#define _RELAXPOSSTRATEGY_H

#include "AbstractParticle.h"

#include <boost/python.hpp>
using namespace boost::python;

class RelaxPosStrategy
{
public:
	////////////////////////////////////////////////////////////////////////
	// Name:       RelaxPosStrategy::RelaxPos(int particleNum, float kDt, AbstractParticle** particles)
	// Purpose:    Implementation of RelaxPosStrategy::RelaxPos()
	// Parameters:
	// - particleNum
	// - kDt
	// - particles
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void RelaxPos(int particleNum, float kDt, AbstractParticle** particles) = 0;
};

class RelaxPosStrategyWrap : public RelaxPosStrategy, public wrapper<RelaxPosStrategy>
{
public:
	void RelaxPos(int particleNum, float kDt, AbstractParticle** particles)
	{
		this->get_override("RelaxPos")(particleNum, kDt, particles);
	}

	static void ExportClass()
	{
		class_<RelaxPosStrategyWrap, boost::noncopyable>("RelaxPosStrategy")
			.def("RelaxPos", pure_virtual(&RelaxPosStrategy::RelaxPos));
	}
};

#endif