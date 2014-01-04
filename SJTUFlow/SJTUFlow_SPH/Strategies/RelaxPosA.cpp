/***********************************************************************
 * Module:  RelaxPosA.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class RelaxPosA
 ***********************************************************************/

#include "RelaxPosA.h"

////////////////////////////////////////////////////////////////////////
// Name:       RelaxPosA::RelaxPos(int particleNum, float kDt, Particle* particles)
// Purpose:    Implementation of RelaxPosA::RelaxPos()
// Parameters:
// - particleNum
// - kDt
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

void RelaxPosA::RelaxPos(int particleNum, float kDt, AbstractParticle** particles)
{
	// TODO : implement
	for (size_t i=0; i<particleNum; ++i){
        AbstractParticle* pi = particles[i];

        float x = pi->curPos.x;
        float y = pi->curPos.y;

        for (size_t j=0; j<pi->neighbour_count; ++j){
            const AbstractParticle* pj = particles[pi->neighbours[j]];
            float r = pi->r[j];
            float dx = pj->curPos.x - pi->curPos.x;
            float dy = pj->curPos.y - pi->curPos.y;

            float a = 1 - r/kH;
            float d = kDt * kDt * ((pi->nearP+pj->nearP)*a*a*a*kNearNorm + (pi->P+pj->P)*a*a*kNorm) / 2;
            // relax
            x -= d * dx / (r*pi->m);
            y -= d * dy / (r*pi->m);
            // surface tension
            if (pi->m == pj->m){
				x += (kSurfaceTension/pi->m) * pj->m*a*a*kNorm * dx;
				y += (kSurfaceTension/pi->m) * pj->m*a*a*kNorm * dy;
            }

            // viscocity
			float du = pi->vel.x - pj->vel.x;
			float dv = pi->vel.y - pj->vel.y;
            float u = du*dx + dv*dy;
            if (u > 0){
                u /= r;

                float a = 1 - r/kH;
                float I = 0.5f * kDt * a * (kLinearViscocity*u + kQuadraticViscocity*u*u);

                x -= I * dx * kDt;
                y -= I * dy * kDt;
            }
        }
		pi->curPos.x = x;
		pi->curPos.y = y;
		pi->vel.x = (pi->curPos.x - pi->prePos.x) / kDt;
		pi->vel.y = (pi->curPos.y - pi->prePos.y) / kDt;
    }
}

RelaxPosStrategy * RelaxPosA::Create()
{
	return new RelaxPosA;
}

void RelaxPosA::ExportClass()
{
	class_<RelaxPosA, bases<RelaxPosStrategy> >("RelaxPosA", init<>())
		.def("RelaxPos", &RelaxPosA::RelaxPos)
		.def("Create", &RelaxPosA::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
