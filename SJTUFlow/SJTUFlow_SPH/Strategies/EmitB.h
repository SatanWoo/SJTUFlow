/***********************************************************************
 * Module:  EmitB.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class EmitB
 ***********************************************************************/

#if !defined(__SJTUFLOW2_EmitB_h)
#define __SJTUFLOW2_EmitB_h

#include "../utils.h"
#include "../Particle.h"
#include "../EmitStrategy.h"


class EmitB : public EmitStrategy
{
public:
   size_t EmitParticles(int particleNum, float kDt, Particle* particles);

   static EmitStrategy *Create();
   static void ExportClass();

protected:
private:
};

#endif
