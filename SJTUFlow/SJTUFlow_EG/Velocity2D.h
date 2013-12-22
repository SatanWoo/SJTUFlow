//
//  Velocity2D.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-16.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Velocity2D_h
#define Eulter_SE_Velocity2D_h

class Velocity2D
{
public:
    Velocity2D(int size);
    ~Velocity2D();
    
    float *getV(){return v;}
    float *getU(){return u;} // Here use as a previous save container;
    
    void swap();
    
private:
    float *u;
    float *v;
    
    int m_size;
};

#endif
