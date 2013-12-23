//
//  Stable3DProjectStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Stable3DProjectStrategy_h
#define Eulter_SE_Stable3DProjectStrategy_h

#include "ProjectStrategy.h"
#include "BoundaryStrategy.h"

class Stable3DProjectStrategy : public Project3DStrategy
{
public:
	Stable3DProjectStrategy(){}
    Stable3DProjectStrategy(BoundaryStrategy *bs);
    void project(int N, float *velocity_u, float *velocity_v, float *velocity_w, float *p, float *div);

	static Project3DStrategy *Create(BoundaryStrategy *bs);

	static void ExportClass();
};


#endif
