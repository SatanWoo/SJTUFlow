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

class RenderSPHStrategy
{
public:
   virtual void RenderInit() = 0;
   virtual void RenderSPH(int particleNum, Particle* particles, std::string scene) = 0;

protected:
private:

};

// class RenderSPHStrategyWrap : public RenderSPHStrategy, public wrapper<RenderSPHStrategy>
// {
// public:
// 	void RenderInit()
// 	{
// 		this->get_override("RenderInit")();
// 	}
// 	void RenderSPH(int particleNum, Particle* particles, std::string scene)
// 	{
// 		this->get_override("RenderSPH")(particleNum, particles, scene);
// 	}
// };

#endif
