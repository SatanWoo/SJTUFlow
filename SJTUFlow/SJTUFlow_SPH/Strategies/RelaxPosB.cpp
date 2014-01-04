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
        particles[i]->acc.set(0.0f, 0.0f, 0.0f);
        for (int j=1; j < particles[i]->neighbour_count; j++){
            vector3 force;
            float r;
            int nindex;

            nindex = particles[i]->neighbours[j];
            r = particles[i]->r[j];

            if (r < h){
                float h_r;
                vector3 diff;

                h_r = h - r;
                diff = particles[i]->curPos - particles[nindex]->curPos;

                force = (-0.5f * (particles[i]->P + particles[nindex]->P) * SPIKY * h_r / r) * diff;

                vdiff = particles[nindex]->vel - particles[i]->vel;
                vdiff = (VISCOSITY * VIS) * vdiff;

                force += vdiff;
                force *= (h_r * particles[i]->dens * particles[nindex]->dens);

                particles[i]->acc += particles[nindex]->m * force;
                particles[nindex]->acc -= particles[i]->m * force;
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