/***********************************************************************
 * Module:  RenderSPHB.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class RenderSPHB
 ***********************************************************************/

#if !defined(__SJTUFLOW2_RenderSPHB_h)
#define __SJTUFLOW2_RenderSPHB_h

#include "../utils.h"
#include "../Particle.h"
#include "../RenderSPHStrategy.h"


class RenderSPHB : public RenderSPHStrategy
{
public:
   static size_t _particleNum;
   static Particle *_particles;
   void RenderInit();
   void RenderSPH(int particleNum, Particle* particles, std::string scene);

   static RenderSPHStrategy *Create();
   static void ExportClass();
protected:
private:

};

#endif
