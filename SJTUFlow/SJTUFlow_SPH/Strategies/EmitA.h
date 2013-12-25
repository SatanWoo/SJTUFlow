/***********************************************************************
 * Module:  EmitA.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class EmitA
 ***********************************************************************/

#if !defined(__SJTUFLOW2_EmitA_h)
#define __SJTUFLOW2_EmitA_h

#include "../utils.h"
#include "../Particle.h"
#include "../EmitStrategy.h"


class EmitA : public EmitStrategy
{
public:
	EmitA();
	size_t EmitParticles(int particleNum, float kDt, Particle* particles);

	static EmitStrategy *Create();
	static void ExportClass();

protected:
private:
	float Random01() { return (float)rand() / (float)(RAND_MAX-1); }
	float Random(float a, float b) { return a + (b-a)*Random01(); }
	struct Emitter{
		Emitter(){};
		Emitter(float mass, const vector2& position, const vector2& direction, float size, float speed, float delay)
			: mass(mass), position(position), direction(direction), size(size), speed(speed), delay(delay), count(0){
			float len = sqrt(direction.x*direction.x + direction.y*direction.y);
			this->direction.x /= len;
			this->direction.y /= len;
		}
		float mass;
		vector2 position;
		vector2 direction;
		float size;
		float speed;
		float delay;
		size_t count;
	};

	#define kEmitterCount 2
	Emitter emitters[kEmitterCount];
};

#endif
