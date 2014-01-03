/***********************************************************************
 * Module:  RenderSPHStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:28
 * Purpose: Declaration of the class RenderSPHStrategy
 ***********************************************************************/
#ifndef _RENDERSPHSTRATEGY_H
#define _RENDERSPHSTRATEGY_H

#include "AbstractParticle.h"

#include <boost/python.hpp>
using namespace boost::python;

class RenderSPHStrategy
{
public:
	virtual void RenderInit() = 0;
	////////////////////////////////////////////////////////////////////////
	// Name:       RenderSPHStrategy::RenderSPH(int particleNum, AbstractParticle** particles, std::string scene)
	// Purpose:    Implementation of RenderSPHStrategy::RenderSPH()
	// Parameters:
	// - particleNum
	// - particles
	// - scene
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void RenderSPH(int particleNum, AbstractParticle** particles, std::string scene) = 0;
};

class RenderSPHStrategyWrap : public RenderSPHStrategy, public wrapper<RenderSPHStrategy>
{
public:
	void RenderInit()
	{
		this->get_override("RenderInit")();
	}
	void RenderSPH(int particleNum, AbstractParticle** particles, std::string scene)
	{
		this->get_override("RenderSPH")(particleNum, particles, scene);
	}

	static void ExportClass()
	{
		class_<RenderSPHStrategyWrap, boost::noncopyable>("RenderSPHStrategy")
			.def("RenderInit", pure_virtual(&RenderSPHStrategy::RenderInit))
			.def("RenderSPH", pure_virtual(&RenderSPHStrategy::RenderSPH));
	}
};

#endif