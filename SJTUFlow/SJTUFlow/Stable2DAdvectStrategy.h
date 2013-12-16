#ifndef _STABLE2DADVECTSTRATEGY_H
#define _STABLE2DADVECTSTRATEGY_H

#include "AdvectStrategy.h"

class Stable2DAdvectStrategy : public AdvectStrategy
{
public:
	virtual void advect(int size, BounadaryType type, float *d, float *d0, float *u ,float *v, float dt);
};

#endif