/***********************************************************************
 * Module:  EmitA.cpp
 * Author:  zs
 * Modified: 2013��11��21�� 20:26:47
 * Purpose: Implementation of the class EmitA
 ***********************************************************************/

#include "EmitA.h"

////////////////////////////////////////////////////////////////////////
// Name:       EmitA::Emit(int particleNum, Particle* particles)
// Purpose:    Implementation of EmitA::Emit()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

size_t EmitA::EmitParticles(int particleNum, float kDt, Particle* particles)
{
   // TODO : implement
   static size_t particleCount = 0;
    if (particleCount == particleNum)
        return particleCount;

    static int emitDelay = 0;
    if (++emitDelay < 3)
        return particleCount;

    for (size_t emitterIdx=0; emitterIdx<kEmitterCount; ++emitterIdx)
    {
        Emitter& emitter = emitters[emitterIdx];
        if (emitter.count >= kParticleCount/kEmitterCount)
            continue;

        emitter.delay -= kDt*emitDelay;
        if (emitter.delay > 0)
            continue;

        size_t steps = emitter.size / (2*kParticleRadius);

        for (size_t i=0; i<=steps && particleCount<kParticleCount; ++i)
        {
            Particle& pi = particles[particleCount];
            ++particleCount;
            ++emitter.count;

            float ofs = (float)i / (float)steps - 0.5f;

            ofs *= emitter.size;
            pi.curPos.x = emitter.position.x - ofs*emitter.direction.y;
            pi.curPos.y = emitter.position.y + ofs*emitter.direction.x;
            pi.vel.x = emitter.speed * emitter.direction.x*Random(0.9f, 1.1f);
            pi.vel.y = emitter.speed * emitter.direction.y*Random(0.9f, 1.1f);
            pi.m = emitter.mass;
        }
    }

    emitDelay = 0;
    return particleCount;
}
