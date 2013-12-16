#ifndef _STABLE2DPROJECTSTRATEGY_H
#define _STABLE2DPROJECTSTRATEGY_H

#include "ProjectStrategy.h"

class Stable2DProjectStrategy : public ProjectStrategy
{
	virtual void projectStepOne(int size, float *u, float *v, float *p , float *div);
	virtual void projectStepTwo(int size, float *u, float *v, float *p , float *div);
};

#endif