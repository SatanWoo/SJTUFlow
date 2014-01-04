//
//  RelaxPosPoly6.cpp
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#include "RelaxPosPoly6.h"

void RelaxPosPoly6::RelaxPos(int particleNum, float density, AbstractParticle**particles)
{
    for (size_t i = 0; i < particleNum; i++) {
        
        Particle* p = (Particle*)particles[i];
        p->curPos.x += p->vel.x;
        p->curPos.y += p->vel.y;
    }
}

RelaxPosStrategy * RelaxPosPoly6::Create()
{
	return new RelaxPosPoly6;
}

void RelaxPosPoly6::ExportClass()
{
	class_<RelaxPosPoly6, bases<RelaxPosStrategy> >("RelaxPosPoly6", init<>())
		.def("RelaxPos", &RelaxPosPoly6::RelaxPos)
		.def("Create", &RelaxPosPoly6::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
