/***********************************************************************
 * Module:  CalPressureStrategy.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:15
 * Purpose: Declaration of the class CalPressureStrategy
 ***********************************************************************/

#if !defined(__SJTUFLOW2_CalPressureStrategy_h)
#define __SJTUFLOW2_CalPressureStrategy_h

#include "utils.h"
#include "Particle.h"

#include <boost/python.hpp>
using namespace boost::python;

class CalPressureStrategy
{
public:
   virtual void CalPressure(int particleNum, Particle* particles) = 0;

protected:
private:

};

class CalPressureStrategyWrap : public CalPressureStrategy, public wrapper<CalPressureStrategy>
{
public:
	void CalPressure(int particleNum, Particle* particles)
	{
		this->get_override("CalPressure")(particleNum, particles);
	}
};

#endif
