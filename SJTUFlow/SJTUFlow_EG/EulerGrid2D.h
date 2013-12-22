//
//  EulerGrid2D.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-15.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_EulerGrid2D_h
#define Eulter_SE_EulerGrid2D_h

#include "Velocity2D.h"

class EulerGrid2D
{
public:
    EulerGrid2D(int size, float viscocity, float time);
    ~EulerGrid2D();
    
    Velocity2D *getU(){return u;}
    Velocity2D *getV(){return v;}
    Velocity2D *getDensity()const{return density;}
    
	float getCurU(int x, int y)const {return u->getU()[x + (m_size + 2) * y];}
	float getCurV(int x, int y)const {return v->getU()[x + (m_size + 2) * y];}
	float getCurDensity(int x, int y)const {return density->getU()[x + (m_size + 2) * y];}
   
	float getPreU(int x, int y)const {return u->getV()[x + (m_size + 2) * y];}
	float getPreV(int x, int y)const {return v->getV()[x + (m_size + 2) * y];}
	float getPreDensity(int x, int y)const {return density->getV()[x + (m_size + 2) * y];}
 
	void setCurU(int x, int y, float value){u->getU()[x + (m_size + 2) * y] = value;}
	void setCurV(int x, int y, float value){v->getU()[x + (m_size + 2) * y] = value;}
	void setCurDensity(int x, int y, float value){density->getU()[x + (m_size + 2) * y] = value;}

	void setPreU(int x, int y, float value){u->getV()[x + (m_size + 2) * y] = value;}
	void setPreV(int x, int y, float value){v->getV()[x + (m_size + 2) * y] = value;}
	void setPreDensity(int x, int y, float value){density->getV()[x + (m_size + 2) * y] = value;}
    
    float getTime()const{return m_time;}
    float getViscocity()const{return m_viscocity;}

	static void ExportClass();
    
private:
    int m_size;
    float m_viscocity;
    float m_time;
    
    Velocity2D *u;
    Velocity2D *v;
    Velocity2D *density;
};

#endif
