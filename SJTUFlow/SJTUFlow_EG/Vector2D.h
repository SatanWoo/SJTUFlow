//
//  Vector2D.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-15.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_Vector2D_h
#define Eulter_SE_Vector2D_h

class Vector2D
{
public:
    Vector2D();
    ~Vector2D();
    
    void setX(float x){m_x = x;}
    void setY(float y){m_y = y;}
    
    float getX()const {return m_x;}
    float getY()const {return m_y;}

	static void ExportClass();
    
private:
    float m_x;
    float m_y;
};


#endif
