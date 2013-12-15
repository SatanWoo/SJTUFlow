/***********************************************************************
 * Module:  utils.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ23ÈÕ 0:24:58
 * Purpose: Declaration of the class utils
 ***********************************************************************/

#if !defined(__SJTUFLOW2_utils_h)
#define __SJTUFLOW2_utils_h

#include <iostream>
#include <memory.h>
#include <math.h>
#include <GL/glut.h>

#define kScreenWidth 640
#define kScreenHeight 480
#define kViewWidth 10.0f
#define kViewHeight (kScreenHeight*kViewWidth/kScreenWidth)

#define kParticleCount 1000

#define kParticleRadius 0.05f
#define kH (6*kParticleRadius)

#define kNorm (20/(2*kPi*kH*kH))
#define kNearNorm (30/(2*kPi*kH*kH))

#define kPi 3.1415926535f

class vec2{
    public:
    float x,y;
    vec2(float x, float y) : x(x), y(y){}
    vec2(){}
};

#endif
