//
//  StableFluids3DApplication.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-20.
//  Copyright (c) 2013�� Ziqi Wu. All rights reserved.
//

#include "StableFluids3DApplication.h"

#include "Stable3DAdvectStrategy.h"
#include "Stable3DAddSourceStrategy.h"
#include "Stable3DBoundaryStrategy.h"
#include "Stable3DDiffuseStrategy.h"
#include "Stable3DProjectStrategy.h"

#include <QLocalSocket>
#include <QDataStream>

#include <sstream>
#include <fstream>

#include "../SJTUFlow_Global/global.h"

StableFluids3DApplication::StableFluids3DApplication(int size, float timeStep, float diff)
	: EulerApplication(size, timeStep, diff)
{
    grid = new EulerGrid3D(m_size, m_diff, m_time);
	initialize();
}

StableFluids3DApplication::~StableFluids3DApplication()
{
	if (grid) delete grid;
}

void StableFluids3DApplication::initialize()
{
    setAdvectStrategy(new Stable3DAdvectStrategy());
    setDiffuseStrategy(new Stable3DDiffuseStrategy());
    setProjectStrategy(new Stable3DProjectStrategy(new Stable3DBoundaryStrategy()));
    setAddSourceStrategY(new Stable3DAddSourceStrategy());
}

void StableFluids3DApplication::addSourceVelocity()
{
    m_ass->addSource(m_size, grid->getU()->getCurrent(), grid->getU()->getPrevious(), m_time);
    m_ass->addSource(m_size, grid->getV()->getCurrent(), grid->getV()->getPrevious(), m_time);
    m_ass->addSource(m_size, grid->getW()->getCurrent(), grid->getW()->getPrevious(), m_time);
}

void StableFluids3DApplication::addSourceDensity()
{
    m_ass->addSource(m_size, grid->getDensity()->getCurrent(), grid->getDensity()->getPrevious(), m_time);
}

void StableFluids3DApplication::advectVelocity()
{
    grid->getU()->swap();
    grid->getV()->swap();
    grid->getW()->swap();
    
    m_as->advect3D(m_size, BoundaryTypeU, grid->getU()->getCurrent(), grid->getU()->getPrevious(), grid->getU()->getPrevious(), grid->getV()->getPrevious(), grid->getW()->getPrevious(), m_time);
    m_as->advect3D(m_size, BoundaryTypeV, grid->getV()->getCurrent(), grid->getV()->getPrevious(), grid->getU()->getPrevious(), grid->getV()->getPrevious(), grid->getW()->getPrevious(), m_time);
    m_as->advect3D(m_size, BoundaryTypeW, grid->getW()->getCurrent(), grid->getW()->getPrevious(), grid->getU()->getPrevious(), grid->getV()->getPrevious(), grid->getW()->getPrevious(), m_time);
}

void StableFluids3DApplication::advectDensity()
{
    grid->getDensity()->swap();
    
    m_as->advect3D(m_size, BoundaryTypeNone, grid->getDensity()->getCurrent(), grid->getDensity()->getPrevious(), grid->getU()->getCurrent(), grid->getV()->getCurrent(), grid->getW()->getCurrent(), m_time);
}

void StableFluids3DApplication::diffuseVelocity()
{
    grid->getU()->swap();
    grid->getV()->swap();
    grid->getW()->swap();
    
    m_ds->diffuse(m_size, BoundaryTypeU, grid->getU()->getCurrent(), grid->getU()->getPrevious(), m_diff, m_time);
    m_ds->diffuse(m_size, BoundaryTypeV, grid->getV()->getCurrent(), grid->getV()->getPrevious(), m_diff, m_time);
    m_ds->diffuse(m_size, BoundaryTypeW, grid->getW()->getCurrent(), grid->getW()->getPrevious(), m_diff, m_time);
}

void StableFluids3DApplication::diffuseDensity()
{
    grid->getDensity()->swap();
    m_ds->diffuse(m_size, BoundaryTypeNone, grid->getDensity()->getCurrent(), grid->getDensity()->getPrevious(), m_diff, m_time);
}

void StableFluids3DApplication::projectVelocity()
{
    m_ps->project3D(m_size, grid->getU()->getCurrent(), grid->getV()->getCurrent(), grid->getW()->getCurrent(), grid->getU()->getPrevious(), grid->getV()->getPrevious());
}

void StableFluids3DApplication::ExportClass()
{
	class_<StableFluids3DApplication, bases<EulerApplication> >
		("StableFluids3DApplication", init<int, float, float>())
		.def("advectVelocity", &StableFluids3DApplication::advectVelocity)
		.def("advectDensity", &StableFluids3DApplication::advectDensity)
		.def("diffuseVelocity", &StableFluids3DApplication::diffuseVelocity)
		.def("diffuseDensity", &StableFluids3DApplication::diffuseDensity)
		.def("projectVelocity", &StableFluids3DApplication::projectVelocity)
		.def("addSourceVelocity", &StableFluids3DApplication::addSourceVelocity)
		.def("addSourceDensity", &StableFluids3DApplication::addSourceDensity)
		.add_property("grid",
		make_getter(&StableFluids3DApplication::grid, return_value_policy<reference_existing_object>()),
		make_setter(&StableFluids3DApplication::grid, return_value_policy<reference_existing_object>()));
}

void StableFluids3DApplication::display(int i)
{
	int size = (m_size + 2) * (m_size + 2) * (m_size + 2);

	QLocalSocket socket;
	socket.connectToServer("SJTU Flow", QIODevice::ReadWrite);
	if (!socket.waitForConnected(500))
	{
		throw UnconnectedException();
	}
	QDataStream ds(&socket);
	SceneType st = SC_3D;
	SocketType type = SC_EG;
	ds.writeRawData((const char *)(&st), sizeof(SceneType));
	ds.writeRawData((const char *)(&type), sizeof(SocketType));
	ds.writeRawData((const char *)(&m_size), sizeof(int));
	ds.writeRawData((const char *)(&size), sizeof(int));
	ds.writeRawData((const char *)(&i), sizeof(int));
	ds.writeRawData((const char *)(grid->getDensity()->getCurrent()), size * sizeof(float));
	socket.waitForBytesWritten(500);
	socket.disconnectFromServer();

	memset(grid->getDensity()->getPrevious(), 0, size * sizeof(float));
	memset(grid->getU()->getPrevious(), 0, size * sizeof(float));
	memset(grid->getV()->getPrevious(), 0, size * sizeof(float));
	memset(grid->getW()->getPrevious(), 0, size * sizeof(float));
}

void StableFluids3DApplication::saveResults(string rstname, int i)
{
	QLocalSocket socket;
	socket.connectToServer("SJTU Flow", QIODevice::ReadWrite);
	if (!socket.waitForConnected(500))
	{
		throw UnconnectedException();
	}

	stringstream ss;
	ss << i;
	string num;
	ss >> num;
	string realName = rstname + "_" + num + ".txt";

	ofstream out(realName);
	if (!out)
	{
		return;
	}

	out << "#size\n#density velocity_u velocity_v velocity_w\n#...\n";
	int size = (m_size + 2) * (m_size + 2) * (m_size + 2);
	out << size << endl;
	for (int i = 0; i < size; i++)
	{
		out << grid->getDensity()->getCurrent()[i] << " "
			<< grid->getU()->getCurrent()[i] << " "
			<< grid->getV()->getCurrent()[i] << " "
			<< grid->getW()->getCurrent()[i] << "\n";
	}

	out.close();

	memset(grid->getDensity()->getPrevious(), 0, size * sizeof(float));
	memset(grid->getU()->getPrevious(), 0, size * sizeof(float));
	memset(grid->getV()->getPrevious(), 0, size * sizeof(float));
	memset(grid->getW()->getPrevious(), 0, size * sizeof(float));
}
