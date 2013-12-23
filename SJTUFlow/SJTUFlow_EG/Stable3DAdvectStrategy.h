//
//  Stable3DAdvectStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Stable3DAdvectStrategy_h
#define Eulter_SE_Stable3DAdvectStrategy_h

#include "AdvectStrategy.h"

class Stable3DAdvectStrategy : public Advect3DStrategy
{
public:
    virtual void advect(int N, BoundaryType b, float *density, float *density_prev, float *velocity_u, float *velocity_v, float *velocity_w, float dt);

	static Advect3DStrategy *Create();

	static void ExportClass();
};


#endif
