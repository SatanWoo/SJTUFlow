/***********************************************************************
 * Module:  CalPressureB.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class CalPressureB
 ***********************************************************************/

#include "CalPressureB.h"

////////////////////////////////////////////////////////////////////////
// Name:       CalPressureB::CalPressure(int particleNum, Particle* particles)
// Purpose:    Implementation of CalPressureB::CalPressure()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

void CalPressureB::CalPressure(int particleNum, AbstractParticle** particles)
{
   // TODO : implement
    const float STIFF = 1.5f;
    const float POLY6 = 315.0f/(64.0f*kPi*pow(SMOOTHING_LENGTH,9));
    const float h2 = SMOOTHING_LENGTH*SMOOTHING_LENGTH;

    int nindex;
    vector3 dist;

    for (int i = 0; i < particleNum; i++){
		Particle* pi = (Particle*)particles[i];
        pi->dens = 0;
        for (int j=0; j < pi->neighbour_count; j++){
            float density;
            float distsq;

            nindex = pi->neighbours[j];
			Particle* pj = (Particle*)particles[nindex];
            dist = pi->curPos - pj->curPos;
            distsq = dist.lengthSqr();

            float h2_r2;
            h2_r2 = h2 - distsq;
            density = h2_r2 * h2_r2 * h2_r2;
            pi->dens += pi->m * density;
            if (i != nindex){
                pj->dens += pi->m * density;
            }
        }
    }
    for (int i=0; i<particleNum; i++){
		Particle* pi = (Particle*)particles[i];
        pi->dens *= POLY6;
        pi->P = STIFF * (pi->dens - 1000.0f);
        pi->dens = 1.0f / pi->dens;
    }
}

CalPressureStrategy * CalPressureB::Create()
{
	return new CalPressureB;
}

void CalPressureB::ExportClass()
{
	class_<CalPressureB, bases<CalPressureStrategy> >("CalPressureB", init<>())
		.def("CalPressure", &CalPressureB::CalPressure)
		.def("Create", &CalPressureB::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}