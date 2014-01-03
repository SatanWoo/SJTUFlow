#ifndef _STABLE2DDIFFUSESTRATEGY_H
#define _STABLE2DDIFFUSESTRATEGY_H
#include "../SJTUFlow_Global/DiffuseStrategy.h"

class Stable2DDiffuseStrategy : public DiffuseStrategy
{
public:
	void diffuse(int N, BoundaryType b, float * x, float * x0, float diff, float dt);

	static DiffuseStrategy *Create();

	static void ExportClass();
};

#endif