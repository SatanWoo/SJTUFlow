#ifndef _ABSTRACTPARTICLE_H
#define _ABSTRACTPARTICLE_H

#include "mtxlib.h"

class AbstractParticle
{
public:
	vector3 curPos;
	vector3 prePos;
	vector3 vel;
	vector3 acc;
	float m;
	float P;
};

#endif