/***********************************************************************
 * Module:  BodyForceA.h
 * Author:  zs
 * Modified: 2013��11��21�� 20:26:47
 * Purpose: Declaration of the class BodyForceA
 ***********************************************************************/

#if !defined(__SJTUFLOW2_BodyForceA_h)
#define __SJTUFLOW2_BodyForceA_h

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/BodyForceStrategy.h"

class BodyForceA : public BodyForceStrategy
{
public:
	void ApplyBodyForce(int particleNum, float kDt, AbstractParticle** particles);

	static BodyForceStrategy *Create();
	static void ExportClass();
protected:
private:

};

#endif
