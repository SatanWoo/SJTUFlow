//
//  Stable3DProjectStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Stable3DProjectStrategy_h
#define Eulter_SE_Stable3DProjectStrategy_h

#include "../SJTUFlow_Global/ProjectStrategy.h"
#include "../SJTUFlow_Global/BoundaryStrategy.h"

class Stable3DProjectStrategy : public ProjectStrategy
{
public:
	Stable3DProjectStrategy(){}
    Stable3DProjectStrategy(BoundaryStrategy *bs);
	void project(int N, float * u, float * v, float * p, float * div){}
    void project3D(int N, float *velocity_u, float *velocity_v, float *velocity_w, float *p, float *div);

	static ProjectStrategy *Create(BoundaryStrategy *bs);

	static void ExportClass();
};


#endif
