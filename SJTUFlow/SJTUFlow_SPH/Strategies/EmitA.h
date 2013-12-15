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
	EmitA()
	{
		emitters[0] = Emitter(1.0f, vec2(0.05f*kViewWidth, 0.8f*kViewHeight), vec2(4, 1), 0.2f, 5, 0);
		emitters[1] = Emitter(1.4f, vec2(0.05f*kViewWidth, 0.9f*kViewHeight), vec2(4, 1), 0.2f, 5, 6);
	}
	size_t EmitParticles(int particleNum, float kDt, Particle* particles);

protected:
private:
    float Random01() { return (float)rand() / (float)(RAND_MAX-1); }
    float Random(float a, float b) { return a + (b-a)*Random01(); }
    struct Emitter{
		Emitter(){};
        Emitter(float mass, const vec2& position, const vec2& direction, float size, float speed, float delay)
            : mass(mass), position(position), direction(direction), size(size), speed(speed), delay(delay), count(0){
            float len = sqrt(direction.x*direction.x + direction.y*direction.y);
            this->direction.x /= len;
            this->direction.y /= len;
        }
        float mass;
        vec2 position;
        vec2 direction;
        float size;
        float speed;
        float delay;
        size_t count;
    };

    #define kEmitterCount 2
    Emitter emitters[kEmitterCount];
};

#endif
