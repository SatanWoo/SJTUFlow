/***********************************************************************
 * Module:  SPHSolver.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:54
 * Purpose: Implementation of the class SPHSolver
 ***********************************************************************/

#include "SPHSolver.h"

#include "Strategies/Strategies.h"

SPHSolver::SPHSolver()
{
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
// Name:       SPHSolver::SolverDestroy()
// Purpose:    Implementation of SPHSolver::SolverDestroy()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::SolverDestroy(void)
{
   // TODO : implement
   if(emitStrategy)delete emitStrategy;
   if(bodyForceStrategy)delete bodyForceStrategy;
   if(updateGridStrategy)delete updateGridStrategy;
   if(calPressureStrategy)delete calPressureStrategy;
   if(relaxPosStrategy)delete relaxPosStrategy;
   if(collisionStrategy)delete collisionStrategy;
   if(renderSPHStrategy)delete renderSPHStrategy;
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

void SPHSolver::SolverInitSPH(vec2 gs, float dt, int particleNum)
{
   // TODO : implement
   this->dt = dt;
   this->totalParticleNum = particleNum;
   this->curParticleNum = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::SetEmitStrategy(EmitStrategy emitStrategy)
// Purpose:    Implementation of SPHSolver::SetEmitStrategy()
// Parameters:
// - emitStrategy
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::SetEmitStrategy(EmitStrategy *emitStrategy)
{
   // TODO : implement
   this->emitStrategy = emitStrategy;
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::SetBodyForceStrategy(BodyForceStrategy bodyForceStrategy)
// Purpose:    Implementation of SPHSolver::SetBodyForceStrategy()
// Parameters:
// - bodyForceStrategy
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::SetBodyForceStrategy(BodyForceStrategy *bodyForceStrategy)
{
   // TODO : implement
   this->bodyForceStrategy = bodyForceStrategy;
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::SetUpdateGridStrategy(UpdateGridStrategy updateGridStrategy)
// Purpose:    Implementation of SPHSolver::SetUpdateGridStrategy()
// Parameters:
// - updateGridStrategy
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::SetUpdateGridStrategy(UpdateGridStrategy *updateGridStrategy)
{
   // TODO : implement
   this->updateGridStrategy = updateGridStrategy;
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::SetCalPressureStrategy(CalPressureStrategy calPressureStrategy)
// Purpose:    Implementation of SPHSolver::SetCalPressureStrategy()
// Parameters:
// - calPressureStrategy
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::SetCalPressureStrategy(CalPressureStrategy *calPressureStrategy)
{
   // TODO : implement
   this->calPressureStrategy = calPressureStrategy;
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::SetRelaxPosStrategy(RelaxPosStrategy relaxPosStrategy)
// Purpose:    Implementation of SPHSolver::SetRelaxPosStrategy()
// Parameters:
// - relaxPosStrategy
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::SetRelaxPosStrategy(RelaxPosStrategy *relaxPosStrategy)
{
   // TODO : implement
   this->relaxPosStrategy = relaxPosStrategy;
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::SetCollisionStrategy(CollisionStrategy collisionStrategy)
// Purpose:    Implementation of SPHSolver::SetCollisionStrategy()
// Parameters:
// - collisionStrategy
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::SetCollisionStrategy(CollisionStrategy *collisionStrategy)
{
   // TODO : implement
   this->collisionStrategy = collisionStrategy;
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::SetRenderSPHStrategy(RenderSPHStrategy renderSPHStrategy)
// Purpose:    Implementation of SPHSolver::SetRenderSPHStrategy()
// Parameters:
// - renderSPHStrategy
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::SetRenderSPHStrategy(RenderSPHStrategy *renderSPHStrategy)
{
   // TODO : implement
   this->renderSPHStrategy = renderSPHStrategy;
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::Emit()
// Purpose:    Implementation of SPHSolver::Emit()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::Emit(void)
{
	// TODO : implement
	curParticleNum = emitStrategy->EmitParticles(totalParticleNum, dt, particles);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::BodyForce()
// Purpose:    Implementation of SPHSolver::BodyForce()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::BodyForce(void)
{
	// TODO : implement
	bodyForceStrategy->ApplyBodyForce(curParticleNum, dt, particles);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::UpdateGrid()
// Purpose:    Implementation of SPHSolver::UpdateGrid()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::UpdateGrid(void)
{
   // TODO : implement
   updateGridStrategy->UpdateGrid(curParticleNum, particles);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::CalPressure()
// Purpose:    Implementation of SPHSolver::CalPressure()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::CalPressure(void)
{
   // TODO : implement
   calPressureStrategy->CalPressure(curParticleNum, particles);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::RelaxPos()
// Purpose:    Implementation of SPHSolver::RelaxPos()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::RelaxPos(void)
{
   // TODO : implement
   relaxPosStrategy->RelaxPos(curParticleNum, dt, particles);
}

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::Collision()
// Purpose:    Implementation of SPHSolver::Collision()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::Collision(void)
{
   // TODO : implement
   collisionStrategy->Collision(curParticleNum, dt, particles, scene);
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

////////////////////////////////////////////////////////////////////////
// Name:       SPHSolver::RenderSPH()
// Purpose:    Implementation of SPHSolver::RenderSPH()
// Return:     void
////////////////////////////////////////////////////////////////////////

void SPHSolver::RenderSPH(void)
{
   // TODO : implement
   renderSPHStrategy->RenderSPH(curParticleNum, particles, scene);
}

void SPHSolver::ExportClass()
{
	class_<SPHSolver>("SPHSolver", init<>())
		.def("SetScene", &SPHSolver::SetScene)
		.def("SolverInitSPH", &SPHSolver::SolverInitSPH)
		.def("SetEmitStrategy", &SPHSolver::SetEmitStrategy,
		with_custodian_and_ward<1, 2>())
		.def("SetBodyForceStrategy", &SPHSolver::SetBodyForceStrategy, 
		with_custodian_and_ward<1, 2>())
		.def("SetUpdateGridStrategy", &SPHSolver::SetUpdateGridStrategy, 
		with_custodian_and_ward<1, 2>())
		.def("SetCalPressureStrategy", &SPHSolver::SetCalPressureStrategy, with_custodian_and_ward<1, 2>())
		.def("SetRelaxPosStrategy", &SPHSolver::SetRelaxPosStrategy, 
		with_custodian_and_ward<1, 2>())
		.def("SetCollisionStrategy", &SPHSolver::SetCollisionStrategy, 
		with_custodian_and_ward<1, 2>())
		.def("SetRenderSPHStrategy", &SPHSolver::SetRenderSPHStrategy, 
		with_custodian_and_ward<1, 2>())
		.def("Emit", &SPHSolver::Emit)
		.def("BodyForce", &SPHSolver::BodyForce)
		.def("UpdateGrid", &SPHSolver::UpdateGrid)
		.def("CalPressure", &SPHSolver::CalPressure)
		.def("RelaxPos", &SPHSolver::RelaxPos)
		.def("Collision", &SPHSolver::Collision)
		.def("RenderInit", &SPHSolver::RenderInit)
		.def("RenderSPH", &SPHSolver::RenderSPH);
}
