/***********************************************************************
 * Module:  RelaxPosStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:08
 * Purpose: Declaration of the class RelaxPosStrategy
 ***********************************************************************/

#if !defined(__SJTUFLOW2_RelaxPosStrategy_h)
#define __SJTUFLOW2_RelaxPosStrategy_h

#include "utils.h"
#include "Particle.h"

#include <boost/python.hpp>
using namespace boost::python;

class RelaxPosStrategy
{
public:
	////////////////////////////////////////////////////////////////////////
	// Name:       RelaxPosStrategy::RelaxPos(int particleNum, float kDt, Particle* particles)
	// Purpose:    Implementation of RelaxPosStrategy::RelaxPos()
	// Parameters:
	// - particleNum
	// - kDt
	// - particles
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void RelaxPos(int particleNum, float kDt, Particle* particles) = 0;
protected:
private:

};

class RelaxPosStrategyWrap : public RelaxPosStrategy, public wrapper<RelaxPosStrategy>
{
public:
	void RelaxPos(int particleNum, float kDt, Particle* particles);

	static void ExportClass();
};

#endif
