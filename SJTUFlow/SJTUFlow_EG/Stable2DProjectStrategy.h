#ifndef _STABLE2DPROJECTSTRATEGY_H
#define _STABLE2DPROJECTSTRATEGY_H

#include "ProjectStrategy.h"

class Stable2DProjectStrategy : public ProjectStrategy
{
public:
	Stable2DProjectStrategy(){}
    Stable2DProjectStrategy(BoundaryStrategy *bs);
    virtual void project(int N, float * u, float * v, float * p, float * div);

	static ProjectStrategy *Create(BoundaryStrategy *bs);

	static void ExportClass();

private:
};

#endif