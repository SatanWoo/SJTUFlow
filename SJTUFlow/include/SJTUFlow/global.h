#ifndef SJTUFLOW_GLOBAL_H
#define SJTUFLOW_GLOBAL_H

#include <string>

class vec2
{
public:
    float x,y;
    vec2(float x, float y) : x(x), y(y){}
    vec2(){}
};

enum SocketType{SC_SPH = 0, SC_EG_2D, SC_EG_3D};

#define kParticleCount 1000

struct SocketPackageSPH
{
	int particleNum;
	float particlesMass[kParticleCount];
	vec2 particles[kParticleCount];
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