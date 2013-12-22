#ifndef _ADVECTSTRATEGY_H
#define _ADVECTSTRATEGY_H

#include "BoundaryStrategy.h"

class AdvectStrategy
{
public:
	virtual void advect(int N, BoundaryType type, float *density, float *preDensity, float *u, float *v, float dt) = 0;

};

class AdvectStrategyWrap : public AdvectStrategy, public wrapper<AdvectStrategy>
{
public:
	void advect(int N, BoundaryType type, float *density, float *preDensity, float *u, float *v, float dt)
	{
		this->get_override("advect")(N, type, density, preDensity, u, v, dt);
	}

	static void ExportClass()
	{
		class_<AdvectStrategyWrap, boost::noncopyable>("AdvectStrategy")
			.def("advect", pure_virtual(&AdvectStrategy::advect));
	}
};

#endif