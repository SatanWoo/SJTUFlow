/***********************************************************************
 * Module:  BodyForceB.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class BodyForceB
 ***********************************************************************/

#if !defined(__SJTUFLOW2_BodyForceB_h)
#define __SJTUFLOW2_BodyForceB_h

#include "../utils.h"
#include "../Particle.h"
#include "../BodyForceStrategy.h"

class BodyForceB : public BodyForceStrategy
{
public:
   void ApplyBodyForce(int particleNum, float kDt, Particle* particles);

   static BodyForceStrategy *Create();
   static void ExportClass();
protected:
private:

};

#endif
