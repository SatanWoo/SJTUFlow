#ifndef _EULERAPPLICATION_H
#define _EULERAPPLICATION_H

#include "AddSourceStrategy.h"
#include "AdvectStrategy.h"
#include "ProjectStrategy.h"
#include "DiffuseStrategy.h"

#include <iostream>
using namespace std;

#include "StaticVaribles.h"

class EulerApplication
{
public:
	EulerApplication(){}
	EulerApplication(int size, float timeStep, float diff)
		: m_size(size), m_time(timeStep), m_diff(diff){}
	~EulerApplication(){}

	void setAdvectStrategy(AdvectStrategy* as){ m_as = as; }
	void setDiffuseStrategy(DiffuseStrategy* ds){ m_ds = ds; }
	void setProjectStrategy(ProjectStrategy* ps){ m_ps = ps; }
	void setAddSourceStrategY(AddSourceStrategy *ass){ m_ass = ass; }

	virtual void advectVelocity() = 0;
	virtual void advectDensity() = 0;

	virtual void diffuseVelocity() = 0;
	virtual void diffuseDensity() = 0;

	virtual void projectVelocity() = 0;

	virtual void addSourceVelocity() = 0;
	virtual void addSourceDensity() = 0;

	void render(bool guiOn, int i)
	{
		if (guiOn)
		{
			display();
		}
		else
		{
			saveResults(sv.m_rstname, i);
		}
	}

protected:
	AdvectStrategy *m_as;
	DiffuseStrategy *m_ds;
	ProjectStrategy *m_ps;
	AddSourceStrategy *m_ass;

	virtual void display() = 0;
	virtual void saveResults(string rstname, int i) = 0;

	int m_size;
	float m_time;
	float m_diff;
	StaticVaribles sv;
};

class EulerApplicationWrap : public EulerApplication, public wrapper<EulerApplication>
{
public:
	EulerApplicationWrap(int size, float timeStep, float diff) 
		: EulerApplication(size, timeStep, diff){}
	void advectVelocity()
	{
		this->get_override("advectVelocity")();
	}
	void advectDensity()
	{
		this->get_override("advectDensity")();
	}

	void diffuseVelocity()
	{
		this->get_override("diffuseVelocity")();
	}
	void diffuseDensity()
	{
		this->get_override("diffuseDensity")();
	}

	void projectVelocity()
	{
		this->get_override("projectVelocity")();
	}

	void addSourceVelocity()
	{
		this->get_override("addSourceVelocity")();
	}
	void addSourceDensity()
	{
		this->get_override("addSourceDensity")();
	}

	static void ExportClass()
	{
		class_<EulerApplicationWrap, boost::noncopyable>("EulerApplication", init<int, float, float>())
			.def("setAdvectStrategy", &EulerApplication::setAdvectStrategy,
			with_custodian_and_ward<1, 2>())
			.def("setDiffuseStrategy", &EulerApplication::setDiffuseStrategy,
			with_custodian_and_ward<1, 2>())
			.def("setProjectStrategy", &EulerApplication::setProjectStrategy,
			with_custodian_and_ward<1, 2>())
			.def("setAddSourceStrategY", &EulerApplication::setAddSourceStrategY,
			with_custodian_and_ward<1, 2>())
			.def("advectVelocity", pure_virtual(&EulerApplication::advectVelocity))
			.def("advectDensity", pure_virtual(&EulerApplication::advectDensity))
			.def("diffuseVelocity", pure_virtual(&EulerApplication::diffuseVelocity))
			.def("diffuseDensity", pure_virtual(&EulerApplication::diffuseDensity))
			.def("projectVelocity", pure_virtual(&EulerApplication::projectVelocity))
			.def("addSourceVelocity", pure_virtual(&EulerApplication::addSourceVelocity))
			.def("addSourceDensity", pure_virtual(&EulerApplication::addSourceDensity))
			.def("render", &EulerApplication::render);
	}

protected:
	void display()
	{
		this->get_override("display")();
	}

	void saveResults(string rstname, int i)
	{
		this->get_override("saveResults")(rstname, i);
	}
};

#endif