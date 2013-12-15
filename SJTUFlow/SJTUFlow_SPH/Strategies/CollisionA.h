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
	CollisionA()
	{
		walls[0] = Wall( 1,  0, 0);
		walls[1] = Wall( 0,  1, 0);
		walls[2] = Wall(-1,  0, -kViewWidth);
		walls[3] = Wall( 0, -1, -kViewHeight);
	}
	void Collision(int particleNum, float kDt, Particle* particles, std::string scene);

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
