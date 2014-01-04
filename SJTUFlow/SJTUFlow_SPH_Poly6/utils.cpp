//
//  utils.cpp
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#include "utils.h"

float poly6(float r)
{
    if(r <= DISTANCE)
    {
        float tmp = DISTANCE2 - r * r;
        return 315.0f * pow(tmp, 3) / (64.0f * PI * DISTANCE9);
    }
    else
    {
        return 0;
    }
}

Vector2f poly6Grad(float dx, float dy, float r)
{
    float tmp = DISTANCE2 - r * r;
    float b = -945.0f * pow(tmp, 2) / (32.0f * PI * DISTANCE9);
    Vector2f grad(b * dx, b * dy);
    return  grad;
}

float poly6Lap(float r)
{
    float r2 = r * r;
    float res = 945.0f * (DISTANCE2 - 5 * r2) * (DISTANCE2 - r2) / (32.0f * PI * DISTANCE9);
    if (res < 0) {
        res *= -1;
    }
    return res;
}
// spiky kernel for the SPH
float spiky(float r)
{
    return 15.0f * powf(DISTANCE - r, 3) / (PI * DISTANCE6);
}

Vector2f spikyGrad(float dx, float dy, float r)
{
    float tmp = -45.0 * powf(DISTANCE - r, 2) / (PI * DISTANCE6);
    
    Vector2f grad(tmp * dx, tmp * dy);
    return grad;
}

// polynomial core for viscosity
float core_vis(float r)
{
    return 45 * (DISTANCE - r) / (PI * DISTANCE6);
}