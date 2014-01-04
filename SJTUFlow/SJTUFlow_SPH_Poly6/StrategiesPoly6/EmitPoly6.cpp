//
//  EmitePoly6.cpp
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#include "EmitPoly6.h"

int delay = 0;
bool isInitial = false;

size_t EmitPoly6::EmitParticles(int particleNum, float density, AbstractParticle**particles)
{
    if(particleNum == PARTICLE_COUNT)
    {
        return particleNum;
    }
    
    if(delay++ < DELAY)
    {
        return particleNum;
    }
    delay = 0;
    
    if(isInitial == false)
    {
        isInitial = true;
        
        for(int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 100; j++) {
                Particle* pl = (Particle*)particles[particleNum++];
                pl->material = Material(Color(0.6f, 0.7f, 0.9f, 1.0f), 1.0f);
                pl->vel.x = 0.0006;
                pl->curPos.x = i * 0.008 + 0.06;
                pl->curPos.y = j * 0.008 + 0.06;
                pl->isObject = false;
                
                Particle* pr = (Particle*)particles[particleNum++];
                pr->material = Material(Color(0.6f, 0.7f, 0.9f, 1.0f), 1.0f);
                pr->vel.x = -0.0006;
                pr->curPos.x = 0.95 - i * 0.008;
                pr->curPos.y = j * 0.008 + 0.06;
                pr->isObject = false;
            }
        }
    }
    
    /*
    for (size_t i = 0; i < EMITTER_COUNT; i++) {
        Emitter& e = emitters[i];
        Material& m = e.material;
        
        for (size_t j = 0; j < EMIT_SPEED && particleNum < PARTICLE_COUNT ; j++) {
            Particle& p = particles[particleNum++];
            p.material = m;
            p.position = e.position;
            p.velocity.x = e.direction.x * e.velocity.x;
            p.velocity.y = e.direction.y * e.velocity.y;
            p.isObject = false;
        }
    }
     */
    return particleNum;
}

EmitPoly6::EmitPoly6()
{
	emitters[0] = Emitter(
		Material(Color(0.6f, 0.7f, 0.9f, 1.0f), 1.0f),
		Vector2f(0.1f, 0.9f),
		Vector2f(0.03f, 0.0f),
		Vector2f(0.1f, 0.0f),
		0
		);
}

EmitStrategy * EmitPoly6::Create()
{
	return new EmitPoly6;
}

void EmitPoly6::ExportClass()
{
	class_<EmitPoly6, bases<EmitStrategy> >("EmitPoly6", init<>())
		.def("EmitParticles", &EmitPoly6::EmitParticles)
		.def("Create", &EmitPoly6::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
