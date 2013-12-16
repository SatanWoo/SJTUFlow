#ifndef _STABLE2DDIFFUSESTRATEGY_H
#define _STABLE2DDIFFUSESTRATEGY_H
#include "DiffuseStrategy.h"


class Stable2DDiffuseStrategy : public DiffuseStrategy
{
	virtual void diffuse(int size, BounadaryType type, float *x, float *x0, float diff, float dt);
};

#endif