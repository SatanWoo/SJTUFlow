/***********************************************************************
 * Module:  CalPressureStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:15
 * Purpose: Declaration of the class CalPressureStrategy
 ***********************************************************************/

#ifndef _CALPRESSURESTRATEGY_H
#define _CALPRESSURESTRATEGY_H

#include "AbstractParticle.h"

#include <boost/python.hpp>
using namespace boost::python;

class CalPressureStrategy
{
public:
	////////////////////////////////////////////////////////////////////////
	// Name:       CalPressureStrategy::CalPressure(int particleNum, AbstractParticle** particles)
	// Purpose:    Implementation of CalPressureStrategy::CalPressure()
	// Parameters:
	// - particleNum
	// - particles
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void CalPressure(int particleNum, AbstractParticle** particles) = 0;
};

class CalPressureStrategyWrap : public CalPressureStrategy, public wrapper<CalPressureStrategy>
{
public:
	void CalPressure(int particleNum, AbstractParticle** particles)
	{
		this->get_override("CalPressure")(particleNum, particles);
	}

	static void ExportClass()
	{
		class_<CalPressureStrategyWrap, boost::noncopyable>("CalPressureStrategy")
			.def("CalPressure", pure_virtual(&CalPressureStrategy::CalPressure));
	}
};

#endif