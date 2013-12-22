#ifndef _STABLE2DADVECTSTRATEGY_H
#define _STABLE2DADVECTSTRATEGY_H

#include "EulerSolverDll.h"
#include "AdvectStrategy.h"

class EULERSOLVERDLL_API Stable2DAdvectStrategy : public AdvectStrategy
{
public:
	virtual void advect(int size, BoundaryType type, float *d, float *d0, float *u ,float *v, float dt);
};

extern "C"
{
	EULERSOLVERDLL_API AdvectStrategy* getStable2DAdvectStrategy(void);
	typedef AdvectStrategy* (*PFGetStable2DAdvectStrategy)(void);
}

#endif