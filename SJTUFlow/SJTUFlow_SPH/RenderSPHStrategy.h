/***********************************************************************
 * Module:  RenderSPHStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:28
 * Purpose: Declaration of the class RenderSPHStrategy
 ***********************************************************************/

#if !defined(__SJTUFLOW2_RenderSPHStrategy_h)
#define __SJTUFLOW2_RenderSPHStrategy_h

#include "utils.h"
#include "Particle.h"

#include <boost/python.hpp>
using namespace boost::python;

class RenderSPHStrategy
{
public:
	virtual void RenderInit() = 0;
	////////////////////////////////////////////////////////////////////////
	// Name:       RenderSPHStrategy::RenderSPH(int particleNum, Particle* particles, std::string scene)
	// Purpose:    Implementation of RenderSPHStrategy::RenderSPH()
	// Parameters:
	// - particleNum
	// - particles
	// - scene
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void RenderSPH(int particleNum, Particle* particles, std::string scene) = 0;
protected:
private:

};

class RenderSPHStrategyWrap : public RenderSPHStrategy, public wrapper<RenderSPHStrategy>
{
public:
	void RenderInit();
	void RenderSPH(int particleNum, Particle* particles, std::string scene);

	static void ExportClass();
};

#endif
