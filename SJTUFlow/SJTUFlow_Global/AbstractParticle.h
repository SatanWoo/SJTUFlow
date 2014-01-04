#ifndef _ABSTRACTPARTICLE_H
#define _ABSTRACTPARTICLE_H

#include "mtxlib.h"

#define kMaxNeighbourCount 64
class AbstractParticle
{
public:
	int index;
	vector3 curPos;
	vector3 prePos;
	vector3 vel;
	vector3 vel_half;
	vector3 acc;
	float m;
	float P;
	float nearP;
	float dens;
	float nearDens;
	//
	AbstractParticle* next;
	int neighbours[kMaxNeighbourCount];
	float r[kMaxNeighbourCount];
	size_t neighbour_count;
};

#endif