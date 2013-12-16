#ifndef ALGORITHMMANAGER_H
#define ALGORITHMMANAGER_H

#include <Windows.h>

class AlgorithmManager
{
public:
	static AlgorithmManager& GetInstance();
	
public:
	HMODULE hModule;

private:
	AlgorithmManager();
	AlgorithmManager(const AlgorithmManager&);
	AlgorithmManager& operator = (const AlgorithmManager&);
};

#endif