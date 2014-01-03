#ifndef _STABLE2DADVECTSTRATEGY_H
#define _STABLE2DADVECTSTRATEGY_H

#include "../SJTUFlow_Global/AdvectStrategy.h"

class Stable2DAdvectStrategy : public AdvectStrategy
{
public:
	virtual void advect(int N, BoundaryType type, float *d, float *d0, float *u, float *v, float dt);
	void advect3D(int N, BoundaryType type, float *density, float *preDensity, float *u, float *v, float *w, float dt){}

	static AdvectStrategy *Create();

	static void ExportClass();

private:
};

#endif