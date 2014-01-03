/***********************************************************************
 * Module:  CollisionB.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class CollisionB
 ***********************************************************************/

#if !defined(__SJTUFLOW2_CollisionB_h)
#define __SJTUFLOW2_CollisionB_h

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/CollisionStrategy.h"



class CollisionB : public CollisionStrategy
{
public:
   void Collision(int particleNum, float kDt, AbstractParticle** particles, std::string scene);

   static CollisionStrategy *Create();
   static void ExportClass();

protected:
private:
};

#endif
