//
//  RenderSPHPoly6.cpp
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#include "RenderSPHPoly6.h"

#include <QLocalSocket>
#include <QDataStream>

int window_width = 0;
int window_height = 0;

float view_width = 0;
float view_height = 0;

size_t _particle_count = 0;
AbstractParticle**_particles;

#include "../SJTUFlow_Global/global.h"

void RenderSPHPoly6::RenderInit()
{

}

void RenderSPHPoly6::RenderSPH(int particleNum, AbstractParticle**particles, std::string scene)
{
    _particle_count = particleNum;
    _particles = particles;

	SocketPackageSPH sp;
	sp.particleNum = particleNum;
	sp.radius = 0.012;
	for (int i = 0; i < particleNum; i++)
	{
		Particle* p = (Particle*)particles[i];
		sp.particles[i].x = p->curPos.x;
		sp.particles[i].y = p->curPos.y;
		sp.particles[i].z = 0.0;
		sp.particlesMass[i] = 1.0;
	}
	QLocalSocket socket;
	socket.connectToServer("SJTU Flow", QIODevice::ReadWrite);
	if (!socket.waitForConnected(500))
	{
		throw UnconnectedException();
	}
	QDataStream ds(&socket);
	SceneType st = SC_2D;
	SocketType type = SC_SPH;
	ds.writeRawData((const char *)(&st), sizeof(SceneType));
	ds.writeRawData((const char *)(&type), sizeof(SocketType));
	ds.writeRawData((const char *)(&sp), sizeof(SocketPackageSPH));
	socket.waitForBytesWritten(500);
	socket.disconnectFromServer();
}

RenderSPHStrategy * RenderSPHPoly6::Create()
{
	return new RenderSPHPoly6;
}

void RenderSPHPoly6::ExportClass()
{
	class_<RenderSPHPoly6, bases<RenderSPHStrategy> >("RenderSPHPoly6", init<>())
		.def("RenderInit", &RenderSPHPoly6::RenderInit)
		.def("RenderSPH", &RenderSPHPoly6::RenderSPH)
		.def("Create", &RenderSPHPoly6::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
