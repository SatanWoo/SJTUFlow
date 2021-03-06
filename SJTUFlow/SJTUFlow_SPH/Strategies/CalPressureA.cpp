/***********************************************************************
 * Module:  CalPressureA.cpp
 * Author:  zs
 * Modified: 2013��11��21�� 20:26:47
 * Purpose: Implementation of the class CalPressureA
 ***********************************************************************/

#include "CalPressureA.h"

////////////////////////////////////////////////////////////////////////
// Name:       CalPressureA::CalPressure(int particleNum, Particle* particles)
// Purpose:    Implementation of CalPressureA::CalPressure()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

void CalPressureA::CalPressure(int particleNum, AbstractParticle** particles)
{
   // TODO : implement
   for (size_t i=0; i<particleNum; ++i){
        AbstractParticle* pi = particles[i];

        float density = 0;
        float nearDensity = 0;
        for (size_t j=0; j<pi->neighbour_count; ++j)
        {
            const AbstractParticle* pj = particles[pi->neighbours[j]];
            float r = pi->r[j];
            float a = 1 - r/kH;
            density += pj->m * a*a*a * kNorm;
            nearDensity += pj->m * a*a*a*a * kNearNorm;
        }
        pi->dens = density;
        pi->nearDens = nearDensity;
        pi->P = kStiffness * (density - pi->m*kRestDensity);
        pi->nearP = kNearStiffness * nearDensity;
    }
}

CalPressureStrategy * CalPressureA::Create()
{
	return new CalPressureA;
}

void CalPressureA::ExportClass()
{
	class_<CalPressureA, bases<CalPressureStrategy> >("CalPressureA", init<>())
		.def("CalPressure", &CalPressureA::CalPressure)
		.def("Create", &CalPressureA::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
