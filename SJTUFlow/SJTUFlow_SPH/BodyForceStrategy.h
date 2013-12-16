/***********************************************************************
 * Module:  BodyForceStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class BodyForceStrategy
 ***********************************************************************/

#if !defined(__SJTUFLOW2_BodyForceStrategy_h)
#define __SJTUFLOW2_BodyForceStrategy_h

#include "utils.h"
#include "Particle.h"

#include <boost/python.hpp>
using namespace boost::python;

class BodyForceStrategy
{
public:
	////////////////////////////////////////////////////////////////////////
	// Name:       BodyForceStrategy::ApplyBodyForce(int particleNum, float kDt, Particle* particles)
	// Purpose:    Implementation of BodyForceStrategy::ApplyBodyForce()
	// Parameters:
	// - particleNum
	// - kDt
	// - particles
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void ApplyBodyForce(int particleNum, float kDt, Particle* particles) = 0;
protected:
private:

};

class BodyForceStrategyWrap : public BodyForceStrategy, public wrapper<BodyForceStrategy>
{
public:
	void ApplyBodyForce(int particleNum, float kDt, Particle* particles);

	static void ExportClass();
};

#endif
