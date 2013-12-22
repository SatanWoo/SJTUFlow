#ifndef _STABLE2DBOUNDARYSTRATEGY_H
#define _STABLE2DBOUNDARYSTRATEGY_H

#include "EulerSolverDll.h"
#include "BoundaryStrategy.h"

class EULERSOLVERDLL_API Stable2DBoundaryStrategy : public BoundaryStrategy
{
	virtual void setUpBoundary(int size, BoundaryType type, float *boundary);
};

extern "C"
{
	EULERSOLVERDLL_API BoundaryStrategy* getStable2DBoundaryStrategy(void);
	typedef BoundaryStrategy* (*PFGetStable2DBoundaryStrategy)(void);
}

#endif