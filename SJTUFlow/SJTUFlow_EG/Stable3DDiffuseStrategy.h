//
//  Stable3DDiffuseStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Stable3DDiffuseStrategy_h
#define Eulter_SE_Stable3DDiffuseStrategy_h
#include "DiffuseStrategy.h"

class Stable3DDiffuseStrategy : public DiffuseStrategy
{
public:
    void diffuse(int N, BoundaryType b, float *value, float *value_prev, float diff, float dt);

	static DiffuseStrategy *Create();

	static void ExportClass();
};

#endif
