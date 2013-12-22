#include "StableFluidsApplication.h"
#include "Utility.h"

#include "Stable2DAdvectStrategy.h"
#include "Stable2DDiffuseStrategy.h"
#include "Stable2DProjectStrategy.h"
#include "Stable2DBoundaryStrategy.h"
#include "Stable2DAddSourceStrategy.h"

#include <QLocalSocket>
#include <QDataStream>

#include "../include/SJTUFlow/global.h"

StableFluidsApplication::StableFluidsApplication(int size, float timeStep, float diff): m_size(size), m_time(timeStep), m_diff(diff)
{
    grid = new EulerGrid2D(m_size, m_diff, m_time);
	initialize();
}

StableFluidsApplication::~StableFluidsApplication()
{
	if (grid) delete grid;
}

void StableFluidsApplication::initialize()
{
    setAdvectStrategy(new Stable2DAdvectStrategy());
    setDiffuseStrategy(new Stable2DDiffuseStrategy());
    setProjectStrategy(new Stable2DProjectStrategy(new Stable2DBoundaryStrategy()));
    setAddSourceStrategY(new Stable2DAddSourceStrategy());
}

void StableFluidsApplication::addSourceVelocity()
{
    this->m_ass->addSource(m_size, grid->getU()->getU(), grid->getU()->getV(), m_time);
    this->m_ass->addSource(m_size, grid->getV()->getU(), grid->getV()->getV(), m_time);
}

void StableFluidsApplication::addSourceDensity()
{
    this->m_ass->addSource(m_size, grid->getDensity()->getU(), grid->getDensity()->getV(), m_time);
}

void StableFluidsApplication::advectVelocity()
{
    grid->getU()->swap();
    grid->getV()->swap();
    
    this->m_as->advect(m_size, BounadaryTypeHorizontal, grid->getU()->getU(), grid->getU()->getV(), grid->getU()->getV(), grid->getV()->getV(), m_time);
    this->m_as->advect(m_size, BounadaryTypeVertical, grid->getV()->getU(), grid->getV()->getV(), grid->getU()->getV(), grid->getV()->getV(), m_time);
}

void StableFluidsApplication::advectDensity()
{
    grid->getDensity()->swap();
    this->m_as->advect(m_size, BounadaryTypeNone, grid->getDensity()->getU(), grid->getDensity()->getV(), grid->getU()->getU(), grid->getV()->getU(), m_time);

}

void StableFluidsApplication::diffuseVelocity()
{
    grid->getU()->swap();
    this->m_ds->diffuse(m_size, BounadaryTypeHorizontal, grid->getU()->getU(), grid->getU()->getV(), m_diff, m_time);
    grid->getV()->swap();
    this->m_ds->diffuse(m_size, BounadaryTypeVertical, grid->getV()->getU(), grid->getV()->getV(), m_diff, m_time);
}

void StableFluidsApplication::diffuseDensity()
{
    grid->getDensity()->swap();
    this->m_ds->diffuse(m_size, BounadaryTypeNone, grid->getDensity()->getU(), grid->getDensity()->getV(), m_diff, m_time);
}

void StableFluidsApplication::projectVelocity()
{
    this->m_ps->project(m_size, grid->getU()->getU(), grid->getV()->getU(), grid->getU()->getV(), grid->getV()->getV());
}

bool StableFluidsApplication::render()
{
	int size = (m_size + 2) * (m_size + 2);
	QLocalSocket socket;
	socket.connectToServer("SJTU Flow", QIODevice::ReadWrite);
	if (!socket.waitForConnected(3000))
	{
		return false;
	}
	QDataStream ds(&socket);
	SocketType type = SC_EG;
	ds.writeRawData((const char *)(&type), sizeof(SocketType));
	ds.writeRawData((const char *)(&m_size), sizeof(int));
	ds.writeRawData((const char *)(&size), sizeof(int));
	ds.writeRawData((const char *)(grid->getDensity()->getU()), size * sizeof(float));
	socket.waitForBytesWritten(3000);
	socket.disconnectFromServer();
	return true;
}

void StableFluidsApplication::ExportClass()
{
	class_<StableFluidsApplication>("StableFluidsApplication", init<int, float, float>())
		.def("setAdvectStrategy", &StableFluidsApplication::setAdvectStrategy,
		with_custodian_and_ward<1, 2>())
		.def("setDiffuseStrategy", &StableFluidsApplication::setDiffuseStrategy,
		with_custodian_and_ward<1, 2>())
		.def("setProjectStrategy", &StableFluidsApplication::setProjectStrategy,
		with_custodian_and_ward<1, 2>())
		.def("setAddSourceStrategY", &StableFluidsApplication::setAddSourceStrategY,
		with_custodian_and_ward<1, 2>())
		.def("advectVelocity", &StableFluidsApplication::advectVelocity)
		.def("advectDensity", &StableFluidsApplication::advectDensity)
		.def("diffuseVelocity", &StableFluidsApplication::diffuseVelocity)
		.def("diffuseDensity", &StableFluidsApplication::diffuseDensity)
		.def("projectVelocity", &StableFluidsApplication::projectVelocity)
		.def("addSourceVelocity", &StableFluidsApplication::addSourceVelocity)
		.def("addSourceDensity", &StableFluidsApplication::addSourceDensity)
		.def("render", &StableFluidsApplication::render)
		.add_property("grid",
		make_getter(&StableFluidsApplication::grid, return_value_policy<reference_existing_object>()),
		make_setter(&StableFluidsApplication::grid, return_value_policy<reference_existing_object>()));
}
