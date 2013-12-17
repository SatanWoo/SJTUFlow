#ifndef SIMULATIONFRAMEWORK_H
#define SIMULATIONFRAMEWORK_H

#include <Windows.h>

class SimulationFramework
{
public:
	SimulationFramework() {}

	virtual void importAlgorithm(HMODULE hModule) = 0;
};

#endif