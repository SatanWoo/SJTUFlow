//
//  Velocity2D.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-16.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#include "Velocity.h"
#include "Utility.h"
#include <iostream>

Velocity2D::Velocity2D(int size):m_size(size)
{
	int totalSize = (m_size + 2) * (m_size + 2);
    current = new float[totalSize];
	memset(current, 0, totalSize * sizeof(float));
    
    previous = new float[totalSize];
	memset(previous, 0, totalSize * sizeof(float));
}

Velocity2D::~Velocity2D()
{
    if (current) delete [] current;
    if (previous) delete [] previous;
}

void Velocity2D::swap()
{
    SWAP(current, previous);
}

Velocity3D::Velocity3D(int size):m_size(size)
{
	int totalSize = (m_size + 2) * (m_size + 2) * (m_size + 2);
	current = new float[totalSize];
	memset(current, 0, totalSize * sizeof(float));

	previous = new float[totalSize];
	memset(previous, 0, totalSize * sizeof(float));
}
