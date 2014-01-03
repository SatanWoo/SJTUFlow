/***********************************************************************
 * Module:  UpdateGridStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ23ÈÕ 0:24:58
 * Purpose: Declaration of the class UpdateGridStrategy
 ***********************************************************************/
#ifndef _UPDATEGRIDSTRATEGY_H
#define _UPDATEGRIDSTRATEGY_H

#include "AbstractParticle.h"

#include <boost/python.hpp>
using namespace boost::python;

class UpdateGridStrategy
{
public:
	////////////////////////////////////////////////////////////////////////
	// Name:       UpdateGridStrategy::UpdateGrid(int particleNum, AbstractParticle** particles)
	// Purpose:    Implementation of UpdateGridStrategy::UpdateGrid()
	// Parameters:
	// - particleNum
	// - particles
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void UpdateGrid(int particleNum, AbstractParticle** particles) = 0;
};

class UpdateGridStrategyWrap : public UpdateGridStrategy, public wrapper<UpdateGridStrategy>
{
public:
	void UpdateGrid(int particleNum, AbstractParticle** particles)
	{
		this->get_override("UpdateGrid")(particleNum, particles);
	}

	static void ExportClass()
	{
		class_<UpdateGridStrategyWrap, boost::noncopyable>("UpdateGridStrategy")
			.def("UpdateGrid", pure_virtual(&UpdateGridStrategy::UpdateGrid));
	}
};

#endif