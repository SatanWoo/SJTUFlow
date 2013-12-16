#ifndef _STABLE2DBOUNDARYSTRATEGY_H
#define _STABLE2DBOUNDARYSTRATEGY_H

#include "BoundaryStrategy.h"

class Stable2DBoundaryStrategy : public BoundaryStrategy
{
	virtual void setUpBoundary(int size, BounadaryType type, float *boundary);
};

#endif