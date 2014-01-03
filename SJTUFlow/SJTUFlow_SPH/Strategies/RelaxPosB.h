/***********************************************************************
 * Module:  RelaxPosB.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class RelaxPosB
 ***********************************************************************/

#if !defined(__SJTUFLOW2_RelaxPosB_h)
#define __SJTUFLOW2_RelaxPosB_h

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/RelaxPosStrategy.h"

class RelaxPosB : public RelaxPosStrategy
{
public:
   void RelaxPos(int particleNum, float kDt, AbstractParticle** particles);

   static RelaxPosStrategy *Create();
   static void ExportClass();

protected:
private:
};

#endif
