//
//  EmitPoly6.h
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#ifndef __water_SPH2D__EmitPoly6__
#define __water_SPH2D__EmitPoly6__

#include <iostream>

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/EmitStrategy.h"

#define DELAY   10
#define EMIT_SPEED  2

class EmitPoly6 : public EmitStrategy
{
public:
	EmitPoly6();
    size_t EmitParticles(int particleNum, float density, AbstractParticle** particles);

	static EmitStrategy * Create();

	static void ExportClass();
protected:
private:
    
    struct Emitter {
        Emitter() {}
        Emitter(Material _material, Vector2f _position, Vector2f _direction, Vector2f _velocity, int _delay) : material(_material), position(_position), direction(_direction), velocity(_velocity), delay(_delay), count(0) {}
        Material material;
        Vector2f position;
        Vector2f direction;
        Vector2f velocity;
        int delay;
        size_t count;
    };
    
    #define EMITTER_COUNT 1
    
    Emitter emitters[EMITTER_COUNT];
};

#endif /* defined(__water_SPH2D__EmitPoly6__) */
