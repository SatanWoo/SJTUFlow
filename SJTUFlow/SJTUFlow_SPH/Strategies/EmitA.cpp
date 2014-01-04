/***********************************************************************
 * Module:  EmitA.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class EmitA
 ***********************************************************************/

#include "EmitA.h"

EmitA::EmitA()
{
	emitters[0] = Emitter(1.0f, vector2(0.05f*kViewWidth, 0.8f*kViewHeight), vector2(4, 1), 0.2f, 5, 0);
	emitters[1] = Emitter(1.4f, vector2(0.05f*kViewWidth, 0.9f*kViewHeight), vector2(4, 1), 0.2f, 5, 6);
}

////////////////////////////////////////////////////////////////////////
// Name:       EmitA::Emit(int particleNum, float kDt, Particle* particles)
// Purpose:    Implementation of EmitA::Emit()
// Parameters:
// - particleNum
// - kDt
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

size_t EmitA::EmitParticles(int particleNum, float kDt, AbstractParticle** particles)
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
            AbstractParticle* pi = particles[particleCount];
            pi->index = particleCount;
            ++particleCount;
            ++emitter.count;

            float ofs = (float)i / (float)steps - 0.5f;

            ofs *= emitter.size;
            pi->curPos.x = emitter.position.x - ofs*emitter.direction.y;
            pi->curPos.y = emitter.position.y + ofs*emitter.direction.x;
            pi->vel.x = emitter.speed * emitter.direction.x*Random(0.9f, 1.1f);
            pi->vel.y = emitter.speed * emitter.direction.y*Random(0.9f, 1.1f);
            pi->m = emitter.mass;
        }
    }

    emitDelay = 0;
    return particleCount;
}

EmitStrategy * EmitA::Create()
{
	return new EmitA;
}

void EmitA::ExportClass()
{
	class_<EmitA, bases<EmitStrategy> >("EmitA", init<>())
		.def("EmitParticles", &EmitA::EmitParticles)
		.def("Create", &EmitA::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
