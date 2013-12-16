/***********************************************************************
 * Module:  CollisionStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:22
 * Purpose: Declaration of the class CollisionStrategy
 ***********************************************************************/

#if !defined(__SJTUFLOW2_CollisionStrategy_h)
#define __SJTUFLOW2_CollisionStrategy_h

#include "utils.h"
#include "Particle.h"

#include <boost/python.hpp>
using namespace boost::python;

class CollisionStrategy
{
public:
	////////////////////////////////////////////////////////////////////////
	// Name:       CollisionStrategy::Collision(int particleNum, float kDt, Particle* particles, std::string scene)
	// Purpose:    Implementation of CollisionStrategy::Collision()
	// Parameters:
	// - particleNum
	// - kDt
	// - particles
	// - scene
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void Collision(int particleNum, float kDt, Particle* particles, std::string scene) = 0;
protected:
private:

};

class CollisionStrategyWrap : public CollisionStrategy, public wrapper<CollisionStrategy>
{
public:
	void Collision(int particleNum, float kDt, Particle* particles, std::string scene);

	static void ExportClass();
};

#endif
