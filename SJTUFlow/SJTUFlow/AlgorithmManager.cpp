#include "AlgorithmManager.h"

AlgorithmManager::AlgorithmManager()
{
	hModule = NULL;
}

AlgorithmManager& AlgorithmManager::GetInstance()
{
	static AlgorithmManager instance;
	return instance;
}

bool AlgorithmManager::importAlgorithm(SimulationFramework& sf)
{
	if (hModule) {
		sf.importAlgorithm(hModule);
		return true;
	} else {
		return false;
	}
}