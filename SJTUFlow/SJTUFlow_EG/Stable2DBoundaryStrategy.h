#ifndef _STABLE2DBOUNDARYSTRATEGY_H
#define _STABLE2DBOUNDARYSTRATEGY_H
#include "../SJTUFlow_Global/BoundaryStrategy.h"

class Stable2DBoundaryStrategy : public BoundaryStrategy
{
public:
	virtual void setBoundary(int size, BoundaryType type, float *boundary);

	static BoundaryStrategy *Create();

	static void ExportClass();
};

#endif