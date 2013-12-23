//
//  Stable3DAddSourceStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Stable3DAddSourceStrategy_h
#define Eulter_SE_Stable3DAddSourceStrategy_h
#include "AddSourceStrategy.h"

class Stable3DAddSourceStrategy : public AddSourceStrategy
{
public:
    virtual void addSource(int N, float *value, float *value_prev, float dt);

	static AddSourceStrategy *Create();

	static void ExportClass();
};

#endif
