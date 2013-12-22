#ifndef _DIFFUSESTRATEGY_H
#define _DIFFUSESTRATEGY_H

#include "BoundaryStrategy.h"

class DiffuseStrategy
{
public:
	virtual void diffuse(int size, BoundaryType type, float *x, float *x0, float diff, float dt) = 0; 
};

#endif