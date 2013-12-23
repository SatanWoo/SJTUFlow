#ifndef _PROJECTSTRATEGY_H
#define _PROJECTSTRATEGY_H

#include "BoundaryStrategy.h"

#include "boost/python.hpp"
using namespace boost::python;

class ProjectStrategy
{
public:
	virtual void project(int N, float * u, float * v, float * p, float * div) = 0;
protected:
    BoundaryStrategy *m_bs;
};

class ProjectStrategyWrap : public ProjectStrategy, public wrapper<ProjectStrategy>
{
public:
	void project(int N, float * u, float * v, float * p, float * div)
	{
		this->get_override("project")(N, u, v, p, div);
	}

	static void ExportClass()
	{
		class_<ProjectStrategyWrap, boost::noncopyable>("ProjectStrategy")
			.def("project", pure_virtual(&ProjectStrategy::project));
	}
};

class Project3DStrategy
{
public:
	virtual void project(int N, float * u, float * v, float * w, float * p, float * div) = 0;
protected:
	BoundaryStrategy *m_bs;
};

class Project3DStrategyWrap : public Project3DStrategy, public wrapper<Project3DStrategy>
{
public:
	void project(int N, float * u, float * v, float * w, float * p, float * div)
	{
		this->get_override("project")(N, u, v, w, p, div);
	}

	static void ExportClass()
	{
		class_<Project3DStrategyWrap, boost::noncopyable>("Project3DStrategy")
			.def("project", pure_virtual(&Project3DStrategy::project));
	}
};

#endif