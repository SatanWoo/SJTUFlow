//
//  utils.h
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#ifndef water_SPH2D_utils_h
#define water_SPH2D_utils_h

#include <iostream>
#include <math.h>

#define WIDTH_WINDOW    500
#define HEIGHT_WINDOW   500
#define VIEW_LENGTH     10.0f
#define BALL_RADIUS     15.0f

#define EPSILON         0.01f
#define EPSILON2        (EPSILON) * (EPSILON)
#define SUB_STEPS       5
#define DISTANCE        0.8f
#define DISTANCE2       (DISTANCE) * (DISTANCE)
#define DISTANCE6       pow((DISTANCE), 6)
#define DISTANCE9       pow((DISTANCE), 9)
#define PI              3.1415926535f

#define PARTICLE_COUNT  4000

#define GRID_WIDTH  100
#define GRID_HEIGHT 100
#define GRID_SIZE   GRID_WIDTH * GRID_HEIGHT

class Vector2f{
public:
    Vector2f() {}
    Vector2f(float _x, float _y) : x(_x), y(_y){}
    float x, y;
};

class Vector2ui{
public:
    unsigned int x, y;
    Vector2ui() {}
    Vector2ui(unsigned int _x, unsigned int _y) : x(_x), y(_y) {};
};

class Color {
public:
    Color() {}
    Color(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) {}
    float r, g, b, a;
};

class Material {
public:
    Material () {}
    Material (Color _color, float _mass) : color(_color), mass(_mass) {}
    Color color;
    float mass;
};

// poly6 core of the SPH
float poly6(float r);
Vector2f poly6Grad(float dx, float dy, float r);
float poly6Lap(float r);

// skipy kernel for the SPH
float spiky(float r);
Vector2f spikyGrad(float dx, float dy, float r);

// polynomial core for viscosity
float core_vis(float r);

#endif
