#ifndef ALGORITHMMANAGER_H
#define ALGORITHMMANAGER_H

#include <Windows.h>
#include "SimulationFramework.h"

class AlgorithmManager
{
public:
	static AlgorithmManager& GetInstance();
	bool importAlgorithm(SimulationFramework&);
	
public:
	HMODULE hModule;

private:
	AlgorithmManager();
	AlgorithmManager(const AlgorithmManager&);
	AlgorithmManager& operator = (const AlgorithmManager&);
};

#endif