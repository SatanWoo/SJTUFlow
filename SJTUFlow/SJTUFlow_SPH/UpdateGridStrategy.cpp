/***********************************************************************
 * Module:  UpdateGridStrategy.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ23ÈÕ 0:24:58
 * Purpose: Implementation of the class UpdateGridStrategy
 ***********************************************************************/

#include "UpdateGridStrategy.h"

void UpdateGridStrategyWrap::UpdateGrid( int particleNum, Particle* particles )
{
	this->get_override("UpdateGrid")(particleNum, particles);
}

void UpdateGridStrategyWrap::ExportClass()
{
	class_<UpdateGridStrategyWrap, boost::noncopyable>("UpdateGridStrategy")
		.def("UpdateGrid", pure_virtual(&UpdateGridStrategy::UpdateGrid));
}
