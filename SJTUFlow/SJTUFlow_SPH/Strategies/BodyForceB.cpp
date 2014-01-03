/***********************************************************************
 * Module:  BodyForceB.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class BodyForceB
 ***********************************************************************/

#include "BodyForceB.h"

////////////////////////////////////////////////////////////////////////
// Name:       BodyForceB::ApplyBodyForce(int particleNum, AbstractParticle** particles)
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
		Particle* pi = (Particle*)particles[i];
        vector3 v_half;
        vector3 final_acc;

        final_acc = pi->acc + gravity;

        v_half = pi->vel_half + kDt * final_acc;

        pi->curPos += kDt*v_half;

        pi->vel = pi->vel_half + v_half;
        pi->vel *= 0.5f;
        pi->vel_half = v_half;
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
