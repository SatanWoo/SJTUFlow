/***********************************************************************
 * Module:  CollisionStrategy.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:22
 * Purpose: Implementation of the class CollisionStrategy
 ***********************************************************************/

#include "CollisionStrategy.h"

void CollisionStrategyWrap::Collision( int particleNum, float kDt, Particle* particles, std::string scene )
{
	this->get_override("Collision")(particleNum, kDt, particles, scene);
}

void CollisionStrategyWrap::ExportClass()
{
	class_<CollisionStrategyWrap, boost::noncopyable>("CollisionStrategy")
		.def("Collision", pure_virtual(&CollisionStrategy::Collision));
}
