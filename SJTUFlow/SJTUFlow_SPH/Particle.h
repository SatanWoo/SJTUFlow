/***********************************************************************
 * Module:  Particle.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:54
 * Purpose: Declaration of the class Particle
 ***********************************************************************/

#if !defined(__SJTUFLOW2_Particle_h)
#define __SJTUFLOW2_Particle_h

#include "utils.h"

#include "../SJTUFlow_Global/AbstractParticle.h"

#define kMaxNeighbourCount 64
class Particle : public AbstractParticle
{
public:
    int index;
    vector3 vel_half;
    float nearP;
    float dens;
    float nearDens;
    //
    Particle* next;
    int neighbours[kMaxNeighbourCount];
    float r[kMaxNeighbourCount];
    size_t neighbour_count;
};

#endif
