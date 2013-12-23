//
//  MathHelper.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-16.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_MathHelper_h
#define Eulter_SE_MathHelper_h
#include "BoundaryStrategy.h"
#include "Velocity.h"
#include "Utility.h"

class MathHelper
{
public:
//    static void linearCalculation(int size, Velocity2D *x, float a, float c)
//    {
//        linearCalculation(size, x->getU(), x->getV(), a, c);
//    }
//    
    static void linearCalculation(int N, BoundaryType type, float *x, float *x0, float a, float c)
    {
        int i, j, k;
        
        for (k=0 ; k<20 ; k++) {
            FOR_EACH_CELL
			x[IX(i,j)] = (x0[IX(i,j)] + a*(x[IX(i-1,j)]+x[IX(i+1,j)]+x[IX(i,j-1)]+x[IX(i,j+1)]))/c;
            END_FOR
            //set_bnd ( N, b, x );
        }
    }

	static void linearCalculation3D(int N, BoundaryType b, float *value, float *value_prev, float a, float c)
	{
		int count;
		int count_x;
		int count_y;
		int count_z;

		for(count=0; count<10; count++)
		{
			for(count_x=1; count_x<=N; count_x++)
			{
				for(count_y=1; count_y<=N; count_y++)
				{
					for(count_z=1; count_z<=N; count_z++)
					{
						value[IX3D(count_x, count_y, count_z)] =  (value_prev[IX3D(count_x, count_y, count_z)] +
							a * (value[IX3D(count_x-1, count_y, count_z)]+
							value[IX3D(count_x+1, count_y, count_z)]+
							value[IX3D(count_x, count_y-1, count_z)]+
							value[IX3D(count_x, count_y+1, count_z)]+
							value[IX3D(count_x, count_y, count_z-1)]+
							value[IX3D(count_x, count_y, count_z+1)]))/c;
					}
				}
			}
		}
	}
    
private:
    static int linearIndex(int size, int i, int j)
    {
        return i + (size + 2) * j;
    }
};


#endif
