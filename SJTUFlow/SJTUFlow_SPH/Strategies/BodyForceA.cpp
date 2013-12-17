/***********************************************************************
 * Module:  BodyForceA.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class BodyForceA
 ***********************************************************************/

#include "BodyForceA.h"

////////////////////////////////////////////////////////////////////////
// Name:       BodyForceA::ApplyBodyForce(int particleNum, float kDt, Particle* particles)
// Purpose:    Implementation of BodyForceA::ApplyBodyForce()
// Parameters:
// - particleNum
// - kDt
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

void BodyForceA::ApplyBodyForce(int particleNum, float kDt, Particle* particles)
{
   // TODO : implement
   for (size_t i=0; i<particleNum; ++i){
        Particle& pi = particles[i];
        pi.vel.y -= 9.8f * kDt;

        pi.prePos.x = pi.curPos.x;
        pi.prePos.y = pi.curPos.y;

        pi.curPos.x += kDt * pi.vel.x;
        pi.curPos.y += kDt * pi.vel.y;
    }
}

BodyForceStrategy * BodyForceA::Create()
{
	return new BodyForceA;
}

void BodyForceA::ExportClass()
{
	class_<BodyForceA, bases<BodyForceStrategy> >("BodyForceA", init<>())
		.def("ApplyBodyForce", &BodyForceA::ApplyBodyForce)
		.def("Create", &BodyForceA::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
