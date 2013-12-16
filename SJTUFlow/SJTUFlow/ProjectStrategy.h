#ifndef _PROJECTSTRATEGY_H
#define _PROJECTSTRATEGY_H

class ProjectStrategy
{
public:
	virtual void projectStepOne(int size, float *u, float *v, float *p , float *div) = 0;
	virtual void projectStepTwo(int size, float *u, float *v, float *p , float *div) = 0;
};

#endif