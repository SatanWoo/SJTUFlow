#ifndef _ADVECTSTRATEGY_H
#define _ADVECTSTRATEGY_H

#include "BoundaryStrategy.h"

class AdvectStrategy
{
public:
	virtual void advect(int size, BoundaryType type, float *d, float *d0, float *u ,float *v, float dt) = 0;

};

#endif