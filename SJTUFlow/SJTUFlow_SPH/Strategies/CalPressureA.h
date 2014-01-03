/***********************************************************************
 * Module:  CalPressureA.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class CalPressureA
 ***********************************************************************/

#if !defined(__SJTUFLOW2_CalPressureA_h)
#define __SJTUFLOW2_CalPressureA_h

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/CalPressureStrategy.h"

#define kRestDensity 2.0f
#define kStiffness 0.08f
#define kNearStiffness 0.1f

class CalPressureA : public CalPressureStrategy
{
public:
	void CalPressure(int particleNum, AbstractParticle** particles);

	static CalPressureStrategy *Create();
	static void ExportClass();

protected:
private:
};

#endif
