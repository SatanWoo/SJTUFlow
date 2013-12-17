#ifndef _STABLE2DPROJECTSTRATEGY_H
#define _STABLE2DPROJECTSTRATEGY_H

#include "EulerSolverDll.h"
#include "ProjectStrategy.h"

class EULERSOLVERDLL_API Stable2DProjectStrategy : public ProjectStrategy
{
public:
	virtual void projectStepOne(int size, float *u, float *v, float *p , float *div);
	virtual void projectStepTwo(int size, float *u, float *v, float *p , float *div);
};

extern "C"
{
	EULERSOLVERDLL_API ProjectStrategy* getStable2DProjectStrategy(void);
	typedef ProjectStrategy* (*PFGetStable2DProjectStrategy)(void);
}

#endif