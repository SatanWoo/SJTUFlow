//
//  Stable3DBoundaryStrategy.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-21.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Stable3DBoundaryStrategy_h
#define Eulter_SE_Stable3DBoundaryStrategy_h

#include "BoundaryStrategy.h"

class Stable3DBoundaryStrategy : public BoundaryStrategy
{
public:
    virtual void setBoundary(int N, BoundaryType type, float *value);

	static BoundaryStrategy *Create();

	static void ExportClass();
};

#endif
