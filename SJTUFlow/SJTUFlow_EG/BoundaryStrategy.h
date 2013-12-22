#ifndef _BOUNDARYSTRATEGY_H
#define _BOUNDARYSTRATEGY_H

typedef enum
{
	BounadaryTypeNone = 0,
	BounadaryTypeHorizontal = 1,
	BounadaryTypeVertical = 2
}BoundaryType;

#include "boost/python.hpp"
using namespace boost::python;

class BoundaryStrategy
{
public:
	virtual void setUpBoundary(int size, BoundaryType type, float *boundary) = 0;
};

class BoundaryStrategyWrap : public BoundaryStrategy, public wrapper<BoundaryStrategy>
{
public:
	void setUpBoundary(int size, BoundaryType type, float *boundary)
	{
		this->get_override("setUpBoundary")(size, type, boundary);
	}

	static void ExportClass()
	{
		class_<BoundaryStrategyWrap, boost::noncopyable>("BoundaryStrategy")
			.def("setUpBoundary", pure_virtual(&BoundaryStrategy::setUpBoundary));
	}
};

#endif