/***********************************************************************
 * Module:  CollisionA.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class CollisionA
 ***********************************************************************/

#include "CollisionA.h"

////////////////////////////////////////////////////////////////////////
// Name:       CollisionA::Collision(int particleNum, Particle* particles)
// Purpose:    Implementation of CollisionA::Collision()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

void CollisionA::Collision(int particleNum, float kDt, Particle* particles, std::string scene)
{
   // TODO : implement
   for (size_t i=0; i<particleNum; ++i){
        Particle& pi = particles[i];

        for (size_t j=0; j<kWallCount; ++j){
            const Wall& wall = walls[j];
            float dis = wall.nx*pi.curPos.x + wall.ny*pi.curPos.y - wall.c;
            if (dis < kParticleRadius){
                float d = pi.vel.x*wall.nx + pi.vel.y*wall.ny;
                if (dis < 0)dis = 0;
                pi.vel.x += (kParticleRadius - dis) * wall.nx / kDt;
                pi.vel.y += (kParticleRadius - dis) * wall.ny / kDt;
            }
        }
    }
}
