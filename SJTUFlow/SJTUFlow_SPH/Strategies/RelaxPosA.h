/***********************************************************************
 * Module:  RelaxPosA.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class RelaxPosA
 ***********************************************************************/

#if !defined(__SJTUFLOW2_RelaxPosA_h)
#define __SJTUFLOW2_RelaxPosA_h

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/RelaxPosStrategy.h"

#define kSurfaceTension 0.0004f
#define kLinearViscocity 0.5f
#define kQuadraticViscocity 1.0f

class RelaxPosA : public RelaxPosStrategy
{
public:
	void RelaxPos(int particleNum, float kDt, AbstractParticle** particles);

	static RelaxPosStrategy *Create();
	static void ExportClass();

protected:
private:
};

#endif
