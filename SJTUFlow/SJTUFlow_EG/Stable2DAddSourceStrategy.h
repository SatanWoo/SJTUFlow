//
//  Stable2DAddSourceStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-19.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Stable2DAddSourceStrategy_h
#define Eulter_SE_Stable2DAddSourceStrategy_h

#include "../SJTUFlow_Global/AddSourceStrategy.h"

class Stable2DAddSourceStrategy: public AddSourceStrategy
{
public:
    void addSource(int N, float * x, float * s, float dt);

	static AddSourceStrategy *Create();

	static void ExportClass();
};

#endif
