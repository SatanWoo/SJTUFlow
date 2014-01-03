#ifndef SJTUFLOW_GLOBAL_H
#define SJTUFLOW_GLOBAL_H

#include <string>

enum SocketType{SC_SPH = 0, SC_EG};
enum SceneType{SC_2D = 0, SC_3D};

#include "mtxlib.h"

struct SocketPackageSPH
{
	int particleNum;
	float* particlesMass;
	vector3* particles;
};

struct SocketPackageEuler
{
	int size;
	int totalSize;
	float *density;
};

struct UnconnectedException
{
	UnconnectedException()
	{
		msg = "cann't connect to the server.";
	}
	std::string msg;
};

#endif