/***********************************************************************
 * Module:  RenderSPHB.h
 * Author:  zs
 * Modified: 2013��11��21�� 20:26:47
 * Purpose: Declaration of the class RenderSPHB
 ***********************************************************************/

#if !defined(__SJTUFLOW2_RenderSPHB_h)
#define __SJTUFLOW2_RenderSPHB_h

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/RenderSPHStrategy.h"


class RenderSPHB : public RenderSPHStrategy
{
public:
   static size_t _particleNum;
   static AbstractParticle **_particles;
   void RenderInit();
   void RenderSPH(int particleNum, AbstractParticle** particles, std::string scene);

   static RenderSPHStrategy *Create();
   static void ExportClass();
protected:
private:

};

#endif
