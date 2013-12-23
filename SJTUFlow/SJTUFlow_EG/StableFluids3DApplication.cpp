//
//  StableFluids3DApplication.cpp
//  Eulter SE
//
//  Created by satanwoo on 13-12-20.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#include "StableFluids3DApplication.h"

#include "Stable3DAdvectStrategy.h"
#include "Stable3DAddSourceStrategy.h"
#include "Stable3DBoundaryStrategy.h"
#include "Stable3DDiffuseStrategy.h"
#include "Stable3DProjectStrategy.h"

#include <QLocalSocket>
#include <QDataStream>

#include "../include/SJTUFlow/global.h"

StableFluids3DApplication::StableFluids3DApplication(int size, float timeStep, float diff): m_size(size), m_time(timeStep), m_diff(diff)
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
    
    m_as->advect(m_size, BoundaryTypeU, grid->getU()->getCurrent(), grid->getU()->getPrevious(), grid->getU()->getPrevious(), grid->getV()->getPrevious(), grid->getW()->getPrevious(), m_time);
    m_as->advect(m_size, BoundaryTypeV, grid->getV()->getCurrent(), grid->getV()->getPrevious(), grid->getU()->getPrevious(), grid->getV()->getPrevious(), grid->getW()->getPrevious(), m_time);
    m_as->advect(m_size, BoundaryTypeW, grid->getW()->getCurrent(), grid->getW()->getPrevious(), grid->getU()->getPrevious(), grid->getV()->getPrevious(), grid->getW()->getPrevious(), m_time);
}

void StableFluids3DApplication::advectDensity()
{
    grid->getDensity()->swap();
    
    m_as->advect(m_size, BoundaryTypeNone, grid->getDensity()->getCurrent(), grid->getDensity()->getPrevious(), grid->getU()->getCurrent(), grid->getV()->getCurrent(), grid->getW()->getCurrent(), m_time);
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
    m_ps->project(m_size, grid->getU()->getCurrent(), grid->getV()->getCurrent(), grid->getW()->getCurrent(), grid->getU()->getPrevious(), grid->getV()->getPrevious());
}

void StableFluids3DApplication::render()
{
	int size = (m_size + 2) * (m_size + 2) * (m_size + 2);
	QLocalSocket socket;
	socket.connectToServer("SJTU Flow", QIODevice::ReadWrite);
	if (!socket.waitForConnected(3000))
	{
		throw UnconnectedException();
	}
	QDataStream ds(&socket);
	SocketType type = SC_EG_3D;
	ds.writeRawData((const char *)(&type), sizeof(SocketType));
	ds.writeRawData((const char *)(&m_size), sizeof(int));
	ds.writeRawData((const char *)(&size), sizeof(int));
	ds.writeRawData((const char *)(grid->getDensity()->getCurrent()), size * sizeof(float));
	socket.waitForBytesWritten(3000);
	socket.disconnectFromServer();
}

void StableFluids3DApplication::ExportClass()
{
	class_<StableFluids3DApplication>("StableFluids3DApplication", init<int, float, float>())
		.def("setAdvectStrategy", &StableFluids3DApplication::setAdvectStrategy,
		with_custodian_and_ward<1, 2>())
		.def("setDiffuseStrategy", &StableFluids3DApplication::setDiffuseStrategy,
		with_custodian_and_ward<1, 2>())
		.def("setProjectStrategy", &StableFluids3DApplication::setProjectStrategy,
		with_custodian_and_ward<1, 2>())
		.def("setAddSourceStrategY", &StableFluids3DApplication::setAddSourceStrategY,
		with_custodian_and_ward<1, 2>())
		.def("advectVelocity", &StableFluids3DApplication::advectVelocity)
		.def("advectDensity", &StableFluids3DApplication::advectDensity)
		.def("diffuseVelocity", &StableFluids3DApplication::diffuseVelocity)
		.def("diffuseDensity", &StableFluids3DApplication::diffuseDensity)
		.def("projectVelocity", &StableFluids3DApplication::projectVelocity)
		.def("addSourceVelocity", &StableFluids3DApplication::addSourceVelocity)
		.def("addSourceDensity", &StableFluids3DApplication::addSourceDensity)
		.def("render", &StableFluids3DApplication::render)
		.add_property("grid",
		make_getter(&StableFluids3DApplication::grid, return_value_policy<reference_existing_object>()),
		make_setter(&StableFluids3DApplication::grid, return_value_policy<reference_existing_object>()));
}
