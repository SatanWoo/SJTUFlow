/***********************************************************************
 * Module:  BodyForceA.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class BodyForceA
 ***********************************************************************/

#if !defined(__SJTUFLOW2_BodyForceA_h)
#define __SJTUFLOW2_BodyForceA_h

#include "../utils.h"
#include "../Particle.h"
#include "../BodyForceStrategy.h"

class BodyForceA : public BodyForceStrategy
{
public:
	void ApplyBodyForce(int particleNum, float kDt, Particle* particles);

	static BodyForceStrategy *Create();
	static void ExportClass();
protected:
private:

};

#endif
