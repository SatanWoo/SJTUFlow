//
//  BodyForcePoly6.cpp
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#include "BodyForcePoly6.h"

void BodyForcePoly6::ApplyBodyForce( int particleNum, float density,AbstractParticle** particles )
{
    for (size_t i = 0; i < particleNum; i++) {
        Particle* p = (Particle*)particles[i];
        if (p->isObject) {
            continue;
        }
        
        Vector2f fp(0.0f, 0.0f);
        Vector2f fc(0.0f, 0.0f);
        for (size_t j = 0; j < p->neighbour_count; j++) {
            // calculate pressure force
            float dx = p->curPos.x - p->neighbours[j]->curPos.x;
            float dy = p->curPos.y - p->neighbours[j]->curPos.y;
            
            Vector2f tmp_p = spikyGrad(dx, dy, p->distance_neighbours[j]);
            float tmp_c = core_vis(p->distance_neighbours[j]);
            
            if(p->neighbours[j]->isObject)
            {
                fp.x -= P_CORRECT_OBJECT * tmp_p.x * (p->P + p->neighbours[j]->P) / (2.0f * p->neighbours[j]->dens);
                fp.y -= P_CORRECT_OBJECT * tmp_p.y * (p->P + p->neighbours[j]->P) / (2.0f * p->neighbours[j]->dens);
                
                // calculate viscosity force
                
                fc.x += VISCOSITY_OBJECT * p->neighbours[j]->material.mass * (p->neighbours[j]->vel.x - p->vel.x) * tmp_c / p->neighbours[j]->dens;
                fc.y += VISCOSITY_OBJECT * p->neighbours[j]->material.mass * (p->neighbours[j]->vel.y - p->vel.y) * tmp_c / p->neighbours[j]->dens;
            }
            else
            {
                fp.x -= P_CORRECT * tmp_p.x * (p->P + p->neighbours[j]->P) / (2.0f * p->neighbours[j]->dens);
                fp.y -= P_CORRECT * tmp_p.y * (p->P + p->neighbours[j]->P) / (2.0f * p->neighbours[j]->dens);
                
                // calculate viscosity force
                
                fc.x += VISCOSITY * p->neighbours[j]->material.mass * (p->neighbours[j]->vel.x - p->vel.x) * tmp_c / p->neighbours[j]->dens;
                fc.y += VISCOSITY * p->neighbours[j]->material.mass * (p->neighbours[j]->vel.y - p->vel.y) * tmp_c / p->neighbours[j]->dens;
            }
        }
        
        // apply gravity force and viscosity force
        p->vel.y += GRAVITY;
        
        // apply pressure force
        p->vel.x += fp.x + fc.x;
        p->vel.y += fp.y + fc.y;
    }
}

BodyForceStrategy* BodyForcePoly6::Create()
{
	return new BodyForcePoly6;
}

void BodyForcePoly6::ExportClass()
{
	class_<BodyForcePoly6, bases<BodyForceStrategy> >("BodyForcePoly6", init<>())
		.def("ApplyBodyForce", &BodyForcePoly6::ApplyBodyForce)
		.def("Create", &BodyForcePoly6::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
