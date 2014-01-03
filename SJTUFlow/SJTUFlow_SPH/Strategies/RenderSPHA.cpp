/***********************************************************************
 * Module:  RenderSPHA.cpp
 * Author:  zs
 * Modified: 2013年11月21日 20:26:47
 * Purpose: Implementation of the class RenderSPHA
 ***********************************************************************/

#include "RenderSPHA.h"

#include <QLocalSocket>
#include <QDataStream>

size_t RenderSPHA::_particleNum = 0;
AbstractParticle** RenderSPHA::_particles = NULL;

////////////////////////////////////////////////////////////////////////
// Name:       RenderSPHA::Render()
// Purpose:    Implementation of RenderSPHA::Render()
// Parameters:
// Return:     void
////////////////////////////////////////////////////////////////////////

void RenderSPHA::Render()
{
	// TODO : implement
// 	glClearColor(0.02f, 0.01f, 0.01f, 1);
// 	glClear(GL_COLOR_BUFFER_BIT);
// 
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	glOrtho(0, kViewWidth, 0, kViewHeight, 0, 1);
// 
// 	glEnable(GL_POINT_SMOOTH);
// 	glEnable(GL_BLEND);
// 	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	float r = 2.5f*kParticleRadius*kScreenWidth/kViewWidth;

	//绘制粒子 半径r*r
	glPointSize(r*2);

	glBegin(GL_POINTS);
	for(unsigned int i=0; i < RenderSPHA::_particleNum; ++i){
		const Particle* pi = (Particle*)RenderSPHA::_particles[i];
		if(pi->m > 1.0)
			glColor3f(.2,.6,.0);
		else glColor3f(.2,.6,.8);
		glVertex2f(pi->curPos.x, pi->curPos.y);
	}
	glEnd();

	//glutSwapBuffers();
}

////////////////////////////////////////////////////////////////////////
// Name:       RenderSPHA::RenderSPH(int particleNum, Particle* particles, std::string scene)
// Purpose:    Implementation of RenderSPHA::RenderSPH()
// Parameters:
// - particleNum
// - particles
// - scene
// Return:     void
////////////////////////////////////////////////////////////////////////

void RenderSPHA::RenderSPH(int particleNum, AbstractParticle** particles, std::string scene)
{
	// TODO : implement
	_particleNum = particleNum;
	_particles = particles;

	SocketPackageSPH sp;
	sp.particleNum = particleNum;
	sp.particles = new vector3[particleNum];
	sp.particlesMass = new float[particleNum];
	for (int i = 0; i < particleNum; i++)
	{
		sp.particles[i].x = particles[i]->curPos.x;
		sp.particles[i].y = particles[i]->curPos.y;
		sp.particles[i].z = 0.0;
		sp.particlesMass[i] = particles[i]->m;
	}
	QLocalSocket socket;
	socket.connectToServer("SJTU Flow", QIODevice::ReadWrite);
	if (!socket.waitForConnected(500))
	{
		delete[] sp.particles;
		delete[] sp.particlesMass;
		throw UnconnectedException();
	}
	QDataStream ds(&socket);
	SceneType st = SC_2D;
	SocketType type = SC_SPH;
	ds.writeRawData((const char *)(&st), sizeof(SceneType));
	ds.writeRawData((const char *)(&type), sizeof(SocketType));
	ds.writeRawData((const char *)(&sp.particleNum), sizeof(int));
	ds.writeRawData((const char *)(sp.particles), particleNum * sizeof(vector3));
	ds.writeRawData((const char *)(sp.particlesMass), particleNum * sizeof(float));
	socket.waitForBytesWritten(500);
	socket.disconnectFromServer();
	//Render();

	delete[] sp.particles;
	delete[] sp.particlesMass;
}

////////////////////////////////////////////////////////////////////////
// Name:       RenderSPHA::RenderInit()
// Purpose:    Implementation of RenderSPHA::RenderInit()
// Parameters:
// Return:     void
////////////////////////////////////////////////////////////////////////

void RenderSPHA::RenderInit()
{
	// TODO : implement
//    glutInitWindowSize(kScreenWidth, kScreenHeight);
//    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
//    glutCreateWindow("SPH");
//    glutDisplayFunc(Render);
}

RenderSPHStrategy * RenderSPHA::Create()
{
	return new RenderSPHA;
}

void RenderSPHA::ExportClass()
{
	class_<RenderSPHA, bases<RenderSPHStrategy> >("RenderSPHA", init<>())
		.def("RenderInit", &RenderSPHA::RenderInit)
		.def("RenderSPH", &RenderSPHA::RenderSPH)
		.def("Create", &RenderSPHA::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
