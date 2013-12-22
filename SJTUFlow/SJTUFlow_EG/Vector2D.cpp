//
//  Vector2D.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-15.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#include "Vector2D.h"

#include "boost/python.hpp"
using namespace boost::python;

Vector2D::Vector2D()
{
    m_x = 0;
    m_y = 0;
}

Vector2D::~Vector2D()
{
    m_x = m_y = 0.0f;
}

void Vector2D::ExportClass()
{
	class_<Vector2D>("Vector2D", init<>())
		.add_property("m_x", &Vector2D::getX, &Vector2D::setX)
		.add_property("m_y", &Vector2D::getY, &Vector2D::setY);
}



