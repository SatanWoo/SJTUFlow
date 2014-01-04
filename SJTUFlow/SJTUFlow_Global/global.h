#ifndef SJTUFLOW_GLOBAL_H
#define SJTUFLOW_GLOBAL_H

#include <string>

enum SocketType{SC_SPH = 0, SC_EG};
enum SceneType{SC_2D = 0, SC_3D};

#include "mtxlib.h"

#define KPN 4000

struct SocketPackageSPH
{
	int particleNum;
	float radius;
	float particlesMass[KPN];
	vector3 particles[KPN];
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