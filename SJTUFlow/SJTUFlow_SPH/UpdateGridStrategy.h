/***********************************************************************
 * Module:  UpdateGridStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ23ÈÕ 0:24:58
 * Purpose: Declaration of the class UpdateGridStrategy
 ***********************************************************************/

#if !defined(__SJTUFLOW2_UpdateGridStrategy_h)
#define __SJTUFLOW2_UpdateGridStrategy_h

#include "utils.h"
#include "Particle.h"

#include <boost/python.hpp>
using namespace boost::python;

class UpdateGridStrategy
{
public:
   virtual void UpdateGrid(int particleNum, Particle* particles) = 0;

protected:
private:

};

class UpdateGridStrategyWrap : public UpdateGridStrategy, public wrapper<UpdateGridStrategy>
{
public:
	void UpdateGrid(int particleNum, Particle* particles)
	{
		this->get_override("UpdateGrid")(particleNum, particles);
	}
};

#endif
