/***********************************************************************
 * Module:  BodyForceB.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class BodyForceB
 ***********************************************************************/

#include "BodyForceB.h"

////////////////////////////////////////////////////////////////////////
// Name:       BodyForceB::ApplyBodyForce(int particleNum, Particle* particles)
// Purpose:    Implementation of BodyForceB::ApplyBodyForce()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

void BodyForceB::ApplyBodyForce(int particleNum, float kDt, AbstractParticle** particles)
{
   // TODO : implement
    vector3 gravity(0.0f, 0.0f, -9.8f);

    for (int i=0; i<particleNum; i++){
        vector3 v_half;
        vector3 final_acc;

        final_acc = particles[i]->acc + gravity;

        v_half = particles[i]->vel_half + kDt * final_acc;

        particles[i]->curPos += kDt*v_half;

        particles[i]->vel = particles[i]->vel_half + v_half;
        particles[i]->vel *= 0.5f;
        particles[i]->vel_half = v_half;
    }
}

BodyForceStrategy * BodyForceB::Create()
{
	return new BodyForceB;
}

void BodyForceB::ExportClass()
{
	class_<BodyForceB, bases<BodyForceStrategy> >("BodyForceB", init<>())
		.def("ApplyBodyForce", &BodyForceB::ApplyBodyForce)
		.def("Create", &BodyForceB::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
