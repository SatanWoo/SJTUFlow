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