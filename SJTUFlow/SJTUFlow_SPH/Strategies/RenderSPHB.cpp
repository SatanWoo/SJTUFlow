/***********************************************************************
 * Module:  RenderSPHB.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class RenderSPHB
 ***********************************************************************/

#include "RenderSPHB.h"

#include <QLocalSocket>
#include <QDataStream>

size_t RenderSPHB::_particleNum = 0;
Particle* RenderSPHB::_particles = NULL;

////////////////////////////////////////////////////////////////////////
// Name:       RenderSPHB::Render()
// Purpose:    Implementation of RenderSPHB::Render()
// Parameters:
// Return:     void
////////////////////////////////////////////////////////////////////////
void set_projview(GLfloat fov){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov,(GLfloat)kScreenWidth/(GLfloat)kScreenHeight,0.03,30.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.25,0.0,0.0,0.0,0.0,0.0,0.0,1.0);
	glScalef(1.5f,1.5f,1.5f);
	matrix44 rotview = IdentityMatrix44();
	glMultMatrixf((GLfloat*)&rotview);
}
void RenderB()
{
   // TODO : implement
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    set_projview(60);

    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for (int i=0; i<RenderSPHB::_particleNum; i++){
        glVertex3fv((GLfloat*)&RenderSPHB::_particles[i].curPos);
    }
    glEnd();
    glutSwapBuffers();
}

////////////////////////////////////////////////////////////////////////
// Name:       RenderSPHB::RenderSPH(int particleNum, Particle* particles)
// Purpose:    Implementation of RenderSPHB::RenderSPH()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

void RenderSPHB::RenderSPH(int particleNum, Particle* particles, std::string scene)
{
   // TODO : implement
   _particleNum = particleNum;
   _particles = particles;

   SocketPackageSPH sp;
   sp.particleNum = particleNum;
   for (int i = 0; i < particleNum; i++)
   {
	   sp.particles[i].x = particles[i].curPos.x;
	   sp.particles[i].y = particles[i].curPos.y;
	   sp.particles[i].z = particles[i].curPos.z;
   }
   QLocalSocket socket;
   socket.connectToServer("SJTU Flow", QIODevice::ReadWrite);
   if (!socket.waitForConnected(3000))
   {
	   throw UnconnectedException();
   }
   QDataStream ds(&socket);
   SceneType st = SC_3D;
   SocketType type = SC_SPH;
   ds.writeRawData((const char *)(&st), sizeof(SceneType));
   ds.writeRawData((const char *)(&type), sizeof(SocketType));
   ds.writeRawData((const char *)(&sp), sizeof(SocketPackageSPH));
   socket.waitForBytesWritten(3000);
   socket.disconnectFromServer();
   //RenderB();
}

////////////////////////////////////////////////////////////////////////
// Name:       RenderSPHB::RenderInit()
// Purpose:    Implementation of RenderSPHB::RenderInit()
// Parameters:
// Return:     void
////////////////////////////////////////////////////////////////////////

void RenderSPHB::RenderInit()
{
   // TODO : implement
// 	glutInitWindowSize(kScreenWidth, kScreenHeight);
// 	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
// 	glutCreateWindow("SPH");
// 	glutDisplayFunc(RenderB);
}

RenderSPHStrategy * RenderSPHB::Create()
{
	return new RenderSPHB;
}

void RenderSPHB::ExportClass()
{
	class_<RenderSPHB, bases<RenderSPHStrategy> >("RenderSPHB", init<>())
		.def("RenderInit", &RenderSPHB::RenderInit)
		.def("RenderSPH", &RenderSPHB::RenderSPH)
		.def("Create", &RenderSPHB::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}