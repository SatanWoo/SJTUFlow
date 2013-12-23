//
//  Velocity2D.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-16.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Velocity_h
#define Eulter_SE_Velocity_h

class Velocity2D
{
public:
	Velocity2D(){};
    Velocity2D(int size);
    ~Velocity2D();
    
    float *getPrevious(){return previous;}
    float *getCurrent(){return current;} // Here use as a previous save container;
    
    void swap();
    
protected:
    float *current;
    float *previous;
    
    int m_size;
};

class Velocity3D : public Velocity2D
{
public:
	Velocity3D(int size);

private:
	int m_size;
};

#endif
