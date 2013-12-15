/***********************************************************************
 * Module:  SPHSolver.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:54
 * Purpose: Declaration of the class SPHSolver
 ***********************************************************************/

#if !defined(__SJTUFLOW2_SPHSolver_h)
#define __SJTUFLOW2_SPHSolver_h

#include "EmitStrategy.h"
#include "BodyForceStrategy.h"
#include "UpdateGridStrategy.h"
#include "CalPressureStrategy.h"
#include "RelaxPosStrategy.h"
#include "CollisionStrategy.h"
#include "RenderSPHStrategy.h"

#include "Strategies/EmitA.h"
#include "Strategies/BodyForceA.h"
#include "Strategies/UpdateGridA.h"
#include "Strategies/CalPressureA.h"
#include "Strategies/RelaxPosA.h"
#include "Strategies/CollisionA.h"
#include "Strategies/RenderSPHA.h"

#include "utils.h"
#include <iostream>

class SPHSolver
{
public:
	SPHSolver()
	{
		emitStrategy = new EmitA;
		bodyForceStrategy = new BodyForceA;
		updateGridStrategy = new UpdateGridA;
		calPressureStrategy = new CalPressureA;
		relaxPosStrategy = new RelaxPosA;
		collisionStrategy = new CollisionA;
		renderSPHStrategy = new RenderSPHA;
	}
   void SetScene(std::string fileName);
   void SolverDestroy(void);
   void SolverInitSPH(vec2 gs, float dt, int particleNum);
   void SetEmitStrategy(EmitStrategy *emitStrategy);
   void SetBodyForceStrategy(BodyForceStrategy *bodyForceStrategy);
   void SetUpdateGridStrategy(UpdateGridStrategy *updateGridStrategy);
   void SetCalPressureStrategy(CalPressureStrategy *calPressureStrategy);
   void SetRelaxPosStrategy(RelaxPosStrategy *relaxPosStrategy);
   void SetCollisionStrategy(CollisionStrategy *collisionStrategy);
   void SetRenderSPHStrategy(RenderSPHStrategy *renderSPHStrategy);
   void Emit(void);
   void BodyForce(void);
   void UpdateGrid(void);
   void CalPressure(void);
   void RelaxPos(void);
   void Collision(void);
   void RenderInit(void);
   void RenderSPH(void);

   int emitStrategyType;
   EmitStrategy *emitStrategy;
   BodyForceStrategy *bodyForceStrategy;
   UpdateGridStrategy *updateGridStrategy;
   CalPressureStrategy *calPressureStrategy;
   RelaxPosStrategy *relaxPosStrategy;
   CollisionStrategy *collisionStrategy;
   RenderSPHStrategy *renderSPHStrategy;

protected:
private:
    int curParticleNum;
    int totalParticleNum;
    Particle particles[kParticleCount];
    float dt;
    std::string scene;
};

BOOST_PYTHON_MODULE(SJTUFlow_SPH)
{
	using namespace boost::python;

	class_<vec2>("vec2", init<>())
		.def(init<float, float>())
		.def_readwrite("x", &vec2::x)
		.def_readwrite("y", &vec2::y);

 	class_<EmitStrategyWrap, boost::noncopyable>("EmitStrategy")
 		.def("EmitParticles", pure_virtual(&EmitStrategy::EmitParticles));

	class_<EmitA, bases<EmitStrategy> >("EmitA", init<>())
		.def("EmitParticles", &EmitA::EmitParticles);

 	class_<BodyForceStrategyWrap, boost::noncopyable>("BodyForceStrategy")
 		.def("ApplyBodyForce", pure_virtual(&BodyForceStrategy::ApplyBodyForce));

	class_<BodyForceA, bases<BodyForceStrategy> >("BodyForceA", init<>())
		.def("ApplyBodyForce", &BodyForceA::ApplyBodyForce);

 	class_<UpdateGridStrategyWrap, boost::noncopyable>("UpdateGridStrategy")
 		.def("UpdateGrid", pure_virtual(&UpdateGridStrategy::UpdateGrid));

	class_<UpdateGridA, bases<UpdateGridStrategy> >("UpdateGridA", init<>())
		.def("UpdateGrid", &UpdateGridA::UpdateGrid);

 	class_<CalPressureStrategyWrap, boost::noncopyable>("CalPressureStrategy")
 		.def("CalPressure", pure_virtual(&CalPressureStrategy::CalPressure));

	class_<CalPressureA, bases<CalPressureStrategy> >("CalPressureA", init<>())
		.def("CalPressure", &CalPressureA::CalPressure);

 	class_<RelaxPosStrategyWrap, boost::noncopyable>("RelaxPosStrategy")
 		.def("RelaxPos", pure_virtual(&RelaxPosStrategy::RelaxPos));

	class_<RelaxPosA, bases<RelaxPosStrategy> >("RelaxPosA", init<>())
		.def("RelaxPos", &RelaxPosA::RelaxPos);

 	class_<CollisionStrategyWrap, boost::noncopyable>("CollisionStrategy")
 		.def("Collision", pure_virtual(&CollisionStrategy::Collision));

	class_<CollisionA, bases<CollisionStrategy> >("CollisionA", init<>())
		.def("Collision", &CollisionA::Collision);

// 	class_<RenderSPHStrategyWrap, boost::noncopyable>("RenderSPHStrategy")
// 		.def("RenderInit", pure_virtual(&RenderSPHStrategy::RenderInit))
// 		.def("RenderSPH", pure_virtual(&RenderSPHStrategy::RenderSPH));

// 	class_<RenderSPHA, bases<RenderSPHStrategy> >("RenderSPHA", init<>())
// 		.def("RenderInit", &RenderSPHA::RenderInit)
// 		.def("RenderSPH", &RenderSPHA::RenderSPH);

	class_<SPHSolver>("SPHSolver", init<>())
		.def("SetScene", &SPHSolver::SetScene)
		.def("SolverDestroy", &SPHSolver::SolverDestroy)
		.def("SolverInitSPH", &SPHSolver::SolverInitSPH)
		.def("SetEmitStrategy", &SPHSolver::SetEmitStrategy)
		.def("SetBodyForceStrategy", &SPHSolver::SetBodyForceStrategy)
		.def("SetUpdateGridStrategy", &SPHSolver::SetUpdateGridStrategy)
		.def("SetCalPressureStrategy", &SPHSolver::SetCalPressureStrategy)
		.def("SetRelaxPosStrategy", &SPHSolver::SetRelaxPosStrategy)
		.def("SetCollisionStrategy", &SPHSolver::SetCollisionStrategy)
		/*.def("SetRenderSPHStrategy", &SPHSolver::SetRenderSPHStrategy)*/
		.def("Emit", &SPHSolver::Emit)
		.def("BodyForce", &SPHSolver::BodyForce)
		.def("UpdateGrid", &SPHSolver::UpdateGrid)
		.def("CalPressure", &SPHSolver::CalPressure)
		.def("RelaxPos", &SPHSolver::RelaxPos)
		.def("Collision", &SPHSolver::Collision)
		.def("RenderInit", &SPHSolver::RenderInit)
		.def("RenderSPH", &SPHSolver::RenderSPH);
}

#endif
