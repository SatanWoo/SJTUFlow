//
//  CalPressurePoly6.cpp
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#include "CalPressurePoly6.h"

void CalPressurePoly6::CalPressure(int particleNum, AbstractParticle** particles)
{
    for (size_t i = 0; i < particleNum; i++) {
        Particle* p = (Particle*)particles[i];
        p->dens = 0;
        
        for (size_t j = 0; j < p->neighbour_count; j++) {
            p->dens += p->neighbours[j]->material.mass * spiky(p->distance_neighbours[j]);
        }
        
    }
    
    for (size_t i = 0; i < object_count; i++) {
        Particle& p = objects2D[i];
        p.dens = 0;
        
        for (size_t j = 0; j < p.neighbour_count; j++) {
            p.dens += p.neighbours[j]->material.mass * spiky(p.distance_neighbours[j]);
        }
        
        p.neighbour_count = neighbour_object[i];
    }
    
    for (size_t i = 0; i < particleNum; i++) {
       Particle* p = (Particle*)particles[i];
        p->P = GAS_CONSTANT * (p->dens - DENSITY);
    }
    
    for (size_t i = 0; i < object_count; i++) {
        Particle& p = objects2D[i];
        p.P = GAS_CONSTANT * (p.dens - DENSITY);
    }
}

CalPressureStrategy * CalPressurePoly6::Create()
{
	return new CalPressurePoly6;
}

void CalPressurePoly6::ExportClass()
{
	class_<CalPressurePoly6, bases<CalPressureStrategy> >("CalPressurePoly6", init<>())
		.def("CalPressure", &CalPressurePoly6::CalPressure)
		.def("Create", &CalPressurePoly6::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
