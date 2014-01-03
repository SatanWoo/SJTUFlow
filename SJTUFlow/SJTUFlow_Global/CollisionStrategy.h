/***********************************************************************
 * Module:  CollisionStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:22
 * Purpose: Declaration of the class CollisionStrategy
 ***********************************************************************/
#ifndef _COLLISIONSTRATEGY_H
#define _COLLISIONSTRATEGY_H

#include "AbstractParticle.h"

#include <boost/python.hpp>
using namespace boost::python;
class CollisionStrategy
{
public:
	////////////////////////////////////////////////////////////////////////
	// Name:       CollisionStrategy::Collision(int particleNum, float kDt, AbstractParticle** particles, std::string scene)
	// Purpose:    Implementation of CollisionStrategy::Collision()
	// Parameters:
	// - particleNum
	// - kDt
	// - particles
	// - scene
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void Collision(int particleNum, float kDt, AbstractParticle** particles, std::string scene) = 0;
};

class CollisionStrategyWrap : public CollisionStrategy, public wrapper<CollisionStrategy>
{
public:
	void Collision(int particleNum, float kDt, AbstractParticle** particles, std::string scene)
	{
		this->get_override("Collision")(particleNum, kDt, particles, scene);
	}

	static void ExportClass()
	{
		class_<CollisionStrategyWrap, boost::noncopyable>("CollisionStrategy")
			.def("Collision", pure_virtual(&CollisionStrategy::Collision));
	}
};

#endif