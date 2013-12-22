#ifndef _STABLE2DDIFFUSESTRATEGY_H
#define _STABLE2DDIFFUSESTRATEGY_H

#include "EulerSolverDll.h"
#include "DiffuseStrategy.h"

class EULERSOLVERDLL_API Stable2DDiffuseStrategy : public DiffuseStrategy
{
public:
	virtual void diffuse(int size, BoundaryType type, float *x, float *x0, float diff, float dt);
};

extern "C"
{
	EULERSOLVERDLL_API DiffuseStrategy* getStable2DDiffuseStrategy(void);
	typedef DiffuseStrategy* (*PFGetStable2DDiffuseStrategy)(void);
}

#endif