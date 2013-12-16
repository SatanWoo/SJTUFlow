/***********************************************************************
 * Module:  EmitStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:54
 * Purpose: Declaration of the class EmitStrategy
 ***********************************************************************/

#if !defined(__SJTUFLOW2_EmitStrategy_h)
#define __SJTUFLOW2_EmitStrategy_h

#include "utils.h"
#include "Particle.h"

#include <boost/python.hpp>
using namespace boost::python;

class EmitStrategy
{
public:
	////////////////////////////////////////////////////////////////////////
	// Name:       EmitStrategy::EmitParticles(int particleNum, float kDt, Particle* particles)
	// Purpose:    Implementation of EmitStrategy::EmitParticles()
	// Parameters:
	// - particleNum
	// - kDt
	// - particles
	// Return:     size_t
	////////////////////////////////////////////////////////////////////////
	virtual size_t EmitParticles(int particleNum, float kDt, Particle* particles) = 0;
protected:
private:

};

class EmitStrategyWrap : public EmitStrategy, public wrapper<EmitStrategy>
{
public:
	size_t EmitParticles(int particleNum, float kDt, Particle* particles);

	static void ExportClass();
};

#endif
