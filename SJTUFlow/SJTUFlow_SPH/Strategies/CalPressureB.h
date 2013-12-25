/***********************************************************************
 * Module:  CalPressureB.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class CalPressureB
 ***********************************************************************/

#if !defined(__SJTUFLOW2_CalPressureB_h)
#define __SJTUFLOW2_CalPressureB_h

#include "../utils.h"
#include "../Particle.h"
#include "../CalPressureStrategy.h"

class CalPressureB : public CalPressureStrategy
{
public:
   void CalPressure(int particleNum, Particle* particles);

   static CalPressureStrategy *Create();
   static void ExportClass();

protected:
private:
};

#endif
