/***********************************************************************
 * Module:  CollisionA.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class CollisionA
 ***********************************************************************/

#if !defined(__SJTUFLOW2_CollisionA_h)
#define __SJTUFLOW2_CollisionA_h

#include "../utils.h"
#include "../Particle.h"
#include "../CollisionStrategy.h"



class CollisionA : public CollisionStrategy
{
public:
	CollisionA();
	void Collision(int particleNum, float kDt, Particle* particles, std::string scene);

	static CollisionStrategy *Create();
	static void ExportClass();

protected:
private:
	struct Wall{
		Wall() { }
		Wall(float _nx, float _ny, float _c) : nx(_nx), ny(_ny), c(_c) { }
		float nx;
		float ny;
		float c;
	};
	#define kWallCount 4
	Wall walls[kWallCount];
};

#endif
