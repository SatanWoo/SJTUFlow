//
//  Stable3DAdvectStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Stable3DAdvectStrategy_h
#define Eulter_SE_Stable3DAdvectStrategy_h

#include "../SJTUFlow_Global/AdvectStrategy.h"

class Stable3DAdvectStrategy : public AdvectStrategy
{
public:
	void advect(int size, BoundaryType type, float *d, float *d0, float *u ,float *v, float dt){}
    virtual void advect3D(int N, BoundaryType b, float *density, float *density_prev, float *velocity_u, float *velocity_v, float *velocity_w, float dt);

	static AdvectStrategy *Create();

	static void ExportClass();
};


#endif
