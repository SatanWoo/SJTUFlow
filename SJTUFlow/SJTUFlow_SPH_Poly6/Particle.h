//
//  Particle.h
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#ifndef water_SPH2D_Particle_h
#define water_SPH2D_Particle_h

#include "utils.h"
#include "../SJTUFlow_Global/AbstractParticle.h"

#define NEIGHBOURS_MAX_COUNT    32

class Particle : public AbstractParticle {
public:
    Vector2ui gridCords;
    Material material;

    Particle* next;
    
    const Particle* neighbours[NEIGHBOURS_MAX_COUNT];
    float distance_neighbours[NEIGHBOURS_MAX_COUNT];
    
    bool isObject;
protected:
    
private:
};

#define OBJECT_COUNT    500
#define OBJECT_DISTANCE 0.01f

extern Particle objects2D[OBJECT_COUNT];
extern Particle* grid_object[GRID_SIZE];
extern size_t neighbour_object[OBJECT_COUNT];
extern size_t object_count;
extern Material object_material;

#endif
