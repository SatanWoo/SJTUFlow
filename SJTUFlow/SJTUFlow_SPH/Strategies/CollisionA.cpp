/***********************************************************************
 * Module:  CollisionA.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class CollisionA
 ***********************************************************************/

#include "CollisionA.h"

CollisionA::CollisionA()
{
	walls[0] = Wall( 1,  0, 0);
	walls[1] = Wall( 0,  1, 0);
	walls[2] = Wall(-1,  0, -kViewWidth);
	walls[3] = Wall( 0, -1, -kViewHeight);
}

////////////////////////////////////////////////////////////////////////
// Name:       CollisionA::Collision(int particleNum, float kDt, Particle* particles, std::string scene)
// Purpose:    Implementation of CollisionA::Collision()
// Parameters:
// - particleNum
// - kDt
// - particles
// - scene
// Return:     void
////////////////////////////////////////////////////////////////////////

void CollisionA::Collision(int particleNum, float kDt, AbstractParticle** particles, std::string scene)
{
   // TODO : implement
   for (size_t i=0; i<particleNum; ++i){
        AbstractParticle* pi = particles[i];

        for (size_t j=0; j<kWallCount; ++j){
            const Wall& wall = walls[j];
            float dis = wall.nx*pi->curPos.x + wall.ny*pi->curPos.y - wall.c;
            if (dis < kParticleRadius){
                float d = pi->vel.x*wall.nx + pi->vel.y*wall.ny;
                if (dis < 0)dis = 0;
				pi->vel.x += (kParticleRadius - dis) * wall.nx / kDt;
				pi->vel.y += (kParticleRadius - dis) * wall.ny / kDt;
            }
        }
    }
}

CollisionStrategy * CollisionA::Create()
{
	return new CollisionA;
}

void CollisionA::ExportClass()
{
	class_<CollisionA, bases<CollisionStrategy> >("CollisionA", init<>())
		.def("Collision", &CollisionA::Collision)
		.def("Create", &CollisionA::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
