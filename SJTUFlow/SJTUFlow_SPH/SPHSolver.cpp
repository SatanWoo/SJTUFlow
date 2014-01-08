/***********************************************************************
 * Module:  SPHSolver.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:54
 * Purpose: Implementation of the class SPHSolver
 ***********************************************************************/

#include "SPHSolver.h"

#include "Strategies.h"

#include <sstream>
#include <fstream>

#include <QLocalSocket>

SPHSolver::SPHSolver()
{
	for (int i = 0; i < kParticleCount; i++)
	{
		particlesArray[i] = &particles[i];
	}
	emitStrategy = new EmitA;
	bodyForceStrategy = new BodyForceA;
	updateGridStrategy = new UpdateGridA;
	calPressureStrategy = new CalPressureA;
	relaxPosStrategy = new RelaxPosA;
	collisionStrategy = new CollisionA;
	renderSPHStrategy = new RenderSPHA;
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::SetScene(std::string fileName)
// Purpose:    Implementation of SPHSolver::SetScene()
// Parameters:
// - fileName
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::SetScene(std::string fileName)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::SolverInitSPH(vec2 gs, float dt, int particleNum)
// Purpose:    Implementation of SPHSolver::SolverInitSPH()
// Parameters:
// - gs
// - dt
// - particleNum
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::SolverInitSPH(float dt, int particleNum)
{
   // TODO : implement
   this->dt = dt;
   this->totalParticleNum = particleNum;
   this->curParticleNum = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::Emit()
// Purpose:    Implementation of SPHSolver::Emit()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::Emit(void)
{
	// TODO : implement
	curParticleNum = emitStrategy->EmitParticles(totalParticleNum, dt, particlesArray);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::BodyForce()
// Purpose:    Implementation of SPHSolver::BodyForce()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::BodyForce(void)
{
	// TODO : implement
	bodyForceStrategy->ApplyBodyForce(curParticleNum, dt, particlesArray);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::UpdateGrid()
// Purpose:    Implementation of SPHSolver::UpdateGrid()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::UpdateGrid(void)
{
   // TODO : implement
   updateGridStrategy->UpdateGrid(curParticleNum, particlesArray);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::CalPressure()
// Purpose:    Implementation of SPHSolver::CalPressure()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::CalPressure(void)
{
   // TODO : implement
   calPressureStrategy->CalPressure(curParticleNum, particlesArray);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::RelaxPos()
// Purpose:    Implementation of SPHSolver::RelaxPos()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::RelaxPos(void)
{
   // TODO : implement
   relaxPosStrategy->RelaxPos(curParticleNum, dt, particlesArray);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::Collision()
// Purpose:    Implementation of SPHSolver::Collision()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::Collision(void)
{
   // TODO : implement
   collisionStrategy->Collision(curParticleNum, dt, particlesArray, sv.m_scname);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::RenderInit()
// Purpose:    Implementation of SPHSolver::RenderInit()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::RenderInit(void)
{
   // TODO : implement
   renderSPHStrategy->RenderInit();
}

void SPHSolver::ExportClass()
{
	class_<SPHSolver, bases<AbstractSPHSolver> >("SPHSolver", init<>())
		.def("SetScene", &SPHSolver::SetScene)
		.def("SolverInitSPH", &SPHSolver::SolverInitSPH)
		.def("Emit", &SPHSolver::Emit)
		.def("BodyForce", &SPHSolver::BodyForce)
		.def("UpdateGrid", &SPHSolver::UpdateGrid)
		.def("CalPressure", &SPHSolver::CalPressure)
		.def("RelaxPos", &SPHSolver::RelaxPos)
		.def("Collision", &SPHSolver::Collision)
		.def("RenderInit", &SPHSolver::RenderInit);
}

void SPHSolver::Display()
{
	renderSPHStrategy->RenderSPH(curParticleNum, particlesArray, sv.m_scname);
}

void SPHSolver::SaveResults( std::string rstname, int i )
{
	QLocalSocket socket;
	socket.connectToServer("SJTU Flow", QIODevice::ReadWrite);
	if (!socket.waitForConnected(500))
	{
		throw UnconnectedException();
	}
	using namespace std;
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

	out << "#particle num\n#pos_x pos_y pos_z\n#...\n";
	out << curParticleNum << endl;
	for (int i = 0; i < curParticleNum; i++)
	{
		out << particles[i].curPos.x << " "
			<< particles[i].curPos.y << " "
			<< particles[i].curPos.z << "\n";
	}

	out.close();
}
