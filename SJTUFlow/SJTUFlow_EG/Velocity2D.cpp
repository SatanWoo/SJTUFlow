//
//  Velocity2D.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-16.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#include "Velocity2D.h"
#include "Utility.h"
#include <iostream>

Velocity2D::Velocity2D(int size):m_size(size)
{
	int totalSize = (m_size + 2) * (m_size + 2);
    u = new float[totalSize];
	memset(u, 0, totalSize * sizeof(float));
    //std::cout << u << std::endl;
    
    v = new float[totalSize];
	memset(v, 0, totalSize * sizeof(float));
    //std::cout << v << std::endl;
}

Velocity2D::~Velocity2D()
{
    if (u) delete [] u;
    if (v) delete [] v;
}

void Velocity2D::swap()
{
    SWAP(u, v);
}