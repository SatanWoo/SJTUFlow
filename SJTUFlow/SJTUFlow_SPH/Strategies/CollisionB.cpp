/***********************************************************************
 * Module:  CollisionB.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class CollisionB
 ***********************************************************************/

#include "CollisionB.h"

////////////////////////////////////////////////////////////////////////
// Name:       CollisionB::Collision(int particleNum, Particle* particles)
// Purpose:    Implementation of CollisionB::Collision()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////
const float EPSILON = 0.00001f;
inline void compute_col(vector3* p, vector3* col,const vector3* vel, const vector3* n, float diff, float stiff, float damp){
	float v0;
	float reverse;
	v0 = DotProduct(*n, *vel);
	reverse = stiff * diff - damp * v0;
	*col = (*col)+reverse*(*n);
}
inline void mat4_mulvec3(vector3* dst, const matrix44* m, const vector3* v){
	float new_x;
	float new_y;
	float new_z;
	float inv_w;

	new_x = v->x*m->col[0][0] + v->y*m->col[1][0] + v->z*m->col[2][0] + m->col[3][0];
	new_y = v->x*m->col[0][1] + v->y*m->col[1][1] + v->z*m->col[2][1] + m->col[3][1];
	new_z = v->x*m->col[0][2] + v->y*m->col[1][2] + v->z*m->col[2][2] + m->col[3][2];
	inv_w = 1.0f/(v->x*m->col[0][3] + v->y*m->col[1][3] + v->z*m->col[2][3] + m->col[3][3]);
	dst->x = new_x*inv_w;
	dst->y = new_y*inv_w;
	dst->z = new_z*inv_w;
}
inline void cpu_sph_glass_collision(vector3* p, vector3* col, const vector3* vel, const matrix44* mat, const matrix44* mat_inv, float radius, float stiff, float damp){
	float GLASS_R = 0.05f;
	float GLASS_BOTTOM = -0.08f;
	float GLASS_TOP = 0.06f;
	float GLASS_THICKNESS = 0.01f;

	vector3 p_col;
	vector3 n;
	float diff;

	mat4_mulvec3(&p_col, mat_inv, p);
	diff = 2.0f * radius - (GLASS_R - (float)sqrt(p_col.x * p_col.x + p_col.y * p_col.y));
	if (((diff < 8.0f*radius) && (diff > EPSILON)) && (p_col.z < GLASS_TOP)){
		n.set(-p_col.x, -p_col.y, 0.0f);
		n = n.normalize();
		n = (*mat)*n;
		compute_col(p, col, vel, &n, diff, stiff, damp);
	}
	diff = 2.0f * radius - (p_col.z - GLASS_BOTTOM);
	if (diff > EPSILON){
		n.set(0.0f, 0.0f, 1.0f);
		n = (*mat)*n;
		compute_col(p, col, vel, &n, diff, stiff, damp);
	}
	diff = 2.0f*radius - (GLASS_TOP - p_col.z);
	if (diff > EPSILON){
		n.set(0.0f, 0.0f, -1.0f);
		n = (*mat)*n;
		compute_col(p, col, vel, &n, diff, stiff, damp);
	}
}
void CollisionB::Collision(int particleNum, float kDt, Particle* particles, std::string scene)
{
   // TODO : implement
    static matrix44 _mat_col = IdentityMatrix44();

    matrix44 m;
    m = TranslateMatrix44(0.0f,0.0f,0.0f);
    static matrix44 _mat_inv_col = InvertMatrix44(m);

    float e = 1.0f;
    float sphere_radius = 0.004f;
    float stiff = 30000.0f;
    float damp = 128.0f;

    for (int i = 0; i < particleNum; i++){
        vector3 pre_p;
        vector3 col(0.0f, 0.0f, 0.0f);

        pre_p = particles[i].curPos + kDt * particles[i].vel_half;

        cpu_sph_glass_collision(&pre_p, &col, &particles[i].vel, &_mat_col, &_mat_inv_col, sphere_radius, stiff, damp);
        particles[i].acc += col;
    }
    return;
}

CollisionStrategy * CollisionB::Create()
{
	return new CollisionB;
}

void CollisionB::ExportClass()
{
	class_<CollisionB, bases<CollisionStrategy> >("CollisionB", init<>())
		.def("Collision", &CollisionB::Collision)
		.def("Create", &CollisionB::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}