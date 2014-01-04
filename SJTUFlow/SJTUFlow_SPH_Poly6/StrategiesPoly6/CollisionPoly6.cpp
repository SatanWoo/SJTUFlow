//
//  CollisionPoly6.cpp
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#include "CollisionPoly6.h"

void CollisionPoly6::Collision(int particleNum, float density, AbstractParticle**particles, std::string scene)
{
    for (size_t i = 0; i < particleNum; i++) {
        Particle* p = (Particle*)particles[i];
        float x = p->curPos.x;
        float y = p->curPos.y;
        
        for (size_t j = 0; j < WALL_COUNT; j++) {
            const Wall& wall = walls[j];
            float dis = x * wall.nv.x + y * wall.nv.y + wall.d;
            
            if(dis < 0)
            {
                if (wall.nv.x == 0) {
                    p->vel.y *= -0.9;
                    p->vel.x *= 0.9;
                    if(wall.d > 0)
                    {
                        p->curPos.y = 2 * wall.d - p->curPos.y;
                    }
                    else
                    {
                        p->curPos.y = -2 * wall.d - p->curPos.y;
                    }
                }
                
                if (wall.nv.y == 0)
                {
                    p->vel.x *= -0.9;
                    p->vel.y *= 0.9;
                    if(wall.d > 0)
                    {
                        p->curPos.x = 2 * wall.d - p->curPos.x;
                    }
                    else
                    {
                        p->curPos.x = -2 * wall.d - p->curPos.x;
                    }
                }
            }
        }
    }
}

CollisionStrategy * CollisionPoly6::Create()
{
	return new CollisionPoly6;
}

void CollisionPoly6::ExportClass()
{
	class_<CollisionPoly6, bases<CollisionStrategy> >("CollisionPoly6", init<>())
		.def("Collision", &CollisionPoly6::Collision)
		.def("Create", &CollisionPoly6::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
