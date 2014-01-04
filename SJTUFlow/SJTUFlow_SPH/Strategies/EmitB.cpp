/***********************************************************************
 * Module:  EmitB.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class EmitB
 ***********************************************************************/

#include "EmitB.h"

////////////////////////////////////////////////////////////////////////
// Name:       EmitB::Emit(int particleNum, Particle* particles)
// Purpose:    Implementation of EmitB::Emit()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////
inline float getRand(){
	return rand()/(float)RAND_MAX-0.5f;
}
size_t EmitB::EmitParticles(int particleNum, float kDt, AbstractParticle** particles)
{
   // TODO : implement
    static bool isFirst = 1;
    if (!isFirst)
        return particleNum;
    isFirst = 0;
    const int CUBE_LEN_X = 10;
    const int CUBE_LEN_Y = 10;
    const int LEN_Z = 10;

    const float MASS = 0.00020543f;

    int index;
    float s,s2,s3,cx,cy,cz;

    s = 0.006f;
    cx = cy = 0.0f;
    cz = 0.035f;

    s2 = 0.001f;
    s3 = 0.0001f;

    for (int x=0; x<CUBE_LEN_X; x++){
        for (int y=0; y<CUBE_LEN_Y; y++){
            for (int z=0; z<LEN_Z; z++){
                index = x + y*CUBE_LEN_X + z*CUBE_LEN_X*CUBE_LEN_Y;
                float _x = s*(x -CUBE_LEN_X/2)- cx + s2*getRand();
                float _y = s*(y - CUBE_LEN_Y/2) - cy + s2*getRand();
                float _z = 0.8*s*z - cz;

                particles[index]->curPos.set(_x, _y, _z);
                particles[index]->vel.set(0.0f, 0.0f, 0.0f);
                particles[index]->m = MASS;
                particles[index]->vel_half.set(0.0f, 0.0f, 0.0f);
            }
        }
    }
    return particleNum;
}

EmitStrategy * EmitB::Create()
{
	return new EmitB;
}

void EmitB::ExportClass()
{
	class_<EmitB, bases<EmitStrategy> >("EmitB", init<>())
		.def("EmitParticles", &EmitB::EmitParticles)
		.def("Create", &EmitB::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}