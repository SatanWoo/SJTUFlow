/***********************************************************************
 * Module:  RelaxPosB.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class RelaxPosB
 ***********************************************************************/

#include "RelaxPosB.h"

////////////////////////////////////////////////////////////////////////
// Name:       RelaxPosB::RelaxPos(int particleNum, Particle* particles)
// Purpose:    Implementation of RelaxPosB::RelaxPos()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

void RelaxPosB::RelaxPos(int particleNum, float kDt, AbstractParticle** particles)
{
   // TODO : implement
    const float VISCOSITY = 0.2f;
    const float SPIKY = -45.0f / (kPi * pow(SMOOTHING_LENGTH, 6));
    const float VIS = 45.0f / (kPi * pow(SMOOTHING_LENGTH, 6));

    float h;

    vector3 vdiff;
    h = SMOOTHING_LENGTH;

    for (int i=0; i<particleNum; i++){
		Particle* pi = (Particle*)particles[i];
        pi->acc.set(0.0f, 0.0f, 0.0f);
        for (int j=1; j < pi->neighbour_count; j++){
            vector3 force;
            float r;
            int nindex;

            nindex = pi->neighbours[j];
            r = pi->r[j];

            if (r < h){
				Particle* pj = (Particle*)particles[nindex];
                float h_r;
                vector3 diff;

                h_r = h - r;
                diff = pi->curPos - pj->curPos;

                force = (-0.5f * (pi->P + pj->P) * SPIKY * h_r / r) * diff;

                vdiff = pj->vel - pi->vel;
                vdiff = (VISCOSITY * VIS) * vdiff;

                force += vdiff;
                force *= (h_r * pi->dens * pj->dens);

                pi->acc += pj->m * force;
                pj->acc -= pi->m * force;
            }
        }
    }
}

RelaxPosStrategy * RelaxPosB::Create()
{
	return new RelaxPosB;
}

void RelaxPosB::ExportClass()
{
	class_<RelaxPosB, bases<RelaxPosStrategy> >("RelaxPosB", init<>())
		.def("RelaxPos", &RelaxPosB::RelaxPos)
		.def("Create", &RelaxPosB::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}