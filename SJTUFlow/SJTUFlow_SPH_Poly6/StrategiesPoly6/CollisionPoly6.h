//
//  CollisionPoly6.h
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#ifndef __water_SPH2D__CollisionPoly6__
#define __water_SPH2D__CollisionPoly6__

#include <iostream>

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/CollisionStrategy.h"

#define WALL_COUNT  4

struct Wall {
    Wall() {}
    Wall(float _nx, float _ny, float _d) : nv(_nx, _ny), d(_d) {}
    Vector2f nv;     //normal vector of the line
    float d;        //opposite distance of the line from origin
};

class CollisionPoly6 : public CollisionStrategy
{
public:
	CollisionPoly6()
	{
		walls[0] = Wall(1, 0, -0.05);  //left Wall
		walls[1] = Wall(-1, 0, 0.95); //right Wall
		walls[2] = Wall(0, 1, -0.05);  //bottom Wall
		walls[3] = Wall(0, -1, 0.95); //top Wall
	}
    void Collision(int particleNum, float density, AbstractParticle** particles, std::string scene);

	static CollisionStrategy * Create();

	static void ExportClass();
protected:
private:
    Wall walls[WALL_COUNT];
};

#endif /* defined(__water_SPH2D__CollisionPoly6__) */
