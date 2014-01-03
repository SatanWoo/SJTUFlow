#include "StableFluidsApplication.h"
#include "Utility.h"

#include "Stable2DAdvectStrategy.h"
#include "Stable2DDiffuseStrategy.h"
#include "Stable2DProjectStrategy.h"
#include "Stable2DBoundaryStrategy.h"
#include "Stable2DAddSourceStrategy.h"

#include <QLocalSocket>
#include <QDataStream>

#include <sstream>
#include <fstream>

#include "../SJTUFlow_Global/global.h"

StableFluidsApplication::StableFluidsApplication(int size, float timeStep, float diff)
	: EulerApplication(size, timeStep, diff)
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
    this->m_ass->addSource(m_size, grid->getU()->getCurrent(), grid->getU()->getPrevious(), m_time);
    this->m_ass->addSource(m_size, grid->getV()->getCurrent(), grid->getV()->getPrevious(), m_time);
}

void StableFluidsApplication::addSourceDensity()
{
    this->m_ass->addSource(m_size, grid->getDensity()->getCurrent(), grid->getDensity()->getPrevious(), m_time);
}

void StableFluidsApplication::advectVelocity()
{
    grid->getU()->swap();
    grid->getV()->swap();
    
    this->m_as->advect(m_size, BoundaryTypeU, grid->getU()->getCurrent(), grid->getU()->getPrevious(), grid->getU()->getPrevious(), grid->getV()->getPrevious(), m_time);
    this->m_as->advect(m_size, BoundaryTypeV, grid->getV()->getCurrent(), grid->getV()->getPrevious(), grid->getU()->getPrevious(), grid->getV()->getPrevious(), m_time);
}

void StableFluidsApplication::advectDensity()
{
    grid->getDensity()->swap();
    this->m_as->advect(m_size, BoundaryTypeNone, grid->getDensity()->getCurrent(), grid->getDensity()->getPrevious(), grid->getU()->getCurrent(), grid->getV()->getCurrent(), m_time);

}

void StableFluidsApplication::diffuseVelocity()
{
    grid->getU()->swap();
    this->m_ds->diffuse(m_size, BoundaryTypeU, grid->getU()->getCurrent(), grid->getU()->getPrevious(), m_diff, m_time);
    grid->getV()->swap();
    this->m_ds->diffuse(m_size, BoundaryTypeV, grid->getV()->getCurrent(), grid->getV()->getPrevious(), m_diff, m_time);
}

void StableFluidsApplication::diffuseDensity()
{
    grid->getDensity()->swap();
    this->m_ds->diffuse(m_size, BoundaryTypeNone, grid->getDensity()->getCurrent(), grid->getDensity()->getPrevious(), m_diff, m_time);
}

void StableFluidsApplication::projectVelocity()
{
    this->m_ps->project(m_size, grid->getU()->getCurrent(), grid->getV()->getCurrent(), grid->getU()->getPrevious(), grid->getV()->getPrevious());
}

void StableFluidsApplication::ExportClass()
{
	class_<StableFluidsApplication, bases<EulerApplication> >
		("StableFluidsApplication", init<int, float, float>())
		.def("advectVelocity", &StableFluidsApplication::advectVelocity)
		.def("advectDensity", &StableFluidsApplication::advectDensity)
		.def("diffuseVelocity", &StableFluidsApplication::diffuseVelocity)
		.def("diffuseDensity", &StableFluidsApplication::diffuseDensity)
		.def("projectVelocity", &StableFluidsApplication::projectVelocity)
		.def("addSourceVelocity", &StableFluidsApplication::addSourceVelocity)
		.def("addSourceDensity", &StableFluidsApplication::addSourceDensity)
		.add_property("grid",
		make_getter(&StableFluidsApplication::grid, return_value_policy<reference_existing_object>()),
		make_setter(&StableFluidsApplication::grid, return_value_policy<reference_existing_object>()));
}

void StableFluidsApplication::display()
{
	int size = (m_size + 2) * (m_size + 2);

	QLocalSocket socket;
	socket.connectToServer("SJTU Flow", QIODevice::ReadWrite);
	if (!socket.waitForConnected(500))
	{
		throw UnconnectedException();
	}
	QDataStream ds(&socket);
	SceneType st = SC_2D;
	SocketType type = SC_EG;
	ds.writeRawData((const char *)(&st), sizeof(SceneType));
	ds.writeRawData((const char *)(&type), sizeof(SocketType));
	ds.writeRawData((const char *)(&m_size), sizeof(int));
	ds.writeRawData((const char *)(&size), sizeof(int));
	ds.writeRawData((const char *)(grid->getDensity()->getCurrent()), size * sizeof(float));
	socket.waitForBytesWritten(500);
	socket.disconnectFromServer();

	memset(grid->getDensity()->getPrevious(), 0, size * sizeof(float));
	memset(grid->getU()->getPrevious(), 0, size * sizeof(float));
	memset(grid->getV()->getPrevious(), 0, size * sizeof(float));
}

void StableFluidsApplication::saveResults(string rstname, int i)
{
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

	out << "#size\n#density velocity_u velocity_v\n#...\n";
	int size = (m_size + 2) * (m_size + 2);
	out << size << endl;
	for (int i = 0; i < size; i++)
	{
		out << grid->getDensity()->getCurrent()[i] << " "
			<< grid->getU()->getCurrent()[i] << " "
			<< grid->getV()->getCurrent()[i] << "\n";
	}

	out.close();

	memset(grid->getDensity()->getPrevious(), 0, size * sizeof(float));
	memset(grid->getU()->getPrevious(), 0, size * sizeof(float));
	memset(grid->getV()->getPrevious(), 0, size * sizeof(float));
}
