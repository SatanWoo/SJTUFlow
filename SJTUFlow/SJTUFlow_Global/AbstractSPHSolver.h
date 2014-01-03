#ifndef _ABSTRACTSPHSOLVER_H
#define _ABSTRACTSPHSOLVER_H

#include "EmitStrategy.h"
#include "BodyForceStrategy.h"
#include "UpdateGridStrategy.h"
#include "CalPressureStrategy.h"
#include "RelaxPosStrategy.h"
#include "CollisionStrategy.h"
#include "RenderSPHStrategy.h"

class AbstractSPHSolver
{
public:
	AbstractSPHSolver(){}
	////////////////////////////////////////////////////////////////////////
	// Name:       AbstractSPHSolver::SetScene(std::string fileName)
	// Purpose:    Implementation of AbstractSPHSolver::SetScene()
	// Parameters:
	// - fileName
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void SetScene(std::string fileName) = 0;

	////////////////////////////////////////////////////////////////////////
	// Name:       AbstractSPHSolver::SolverDestroy()
	// Purpose:    Implementation of AbstractSPHSolver::SolverDestroy()
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	void SolverDestroy(void)
	{
		if(emitStrategy)delete emitStrategy;
		if(bodyForceStrategy)delete bodyForceStrategy;
		if(updateGridStrategy)delete updateGridStrategy;
		if(calPressureStrategy)delete calPressureStrategy;
		if(relaxPosStrategy)delete relaxPosStrategy;
		if(collisionStrategy)delete collisionStrategy;
		if(renderSPHStrategy)delete renderSPHStrategy;
	}

	////////////////////////////////////////////////////////////////////////
	// Name:       AbstractSPHSolver::SolverInitSPH(float dt, int particleNum)
	// Purpose:    Implementation of AbstractSPHSolver::SolverInitSPH()
	// Parameters:
	// - dt
	// - particleNum
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	virtual void SolverInitSPH(float dt, int particleNum) = 0;

	////////////////////////////////////////////////////////////////////////
	// Name:       AbstractSPHSolver::SetEmitStrategy(EmitStrategy emitStrategy)
	// Purpose:    Implementation of AbstractSPHSolver::SetEmitStrategy()
	// Parameters:
	// - emitStrategy
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	void SetEmitStrategy(EmitStrategy *emitStrategy)
	{
		this->emitStrategy = emitStrategy;
	}

	////////////////////////////////////////////////////////////////////////
	// Name:       AbstractSPHSolver::SetBodyForceStrategy(BodyForceStrategy bodyForceStrategy)
	// Purpose:    Implementation of AbstractSPHSolver::SetBodyForceStrategy()
	// Parameters:
	// - bodyForceStrategy
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	void SetBodyForceStrategy(BodyForceStrategy *bodyForceStrategy)
	{
		this->bodyForceStrategy = bodyForceStrategy;
	}

	////////////////////////////////////////////////////////////////////////
	// Name:       SPHSolver::SetUpdateGridStrategy(UpdateGridStrategy updateGridStrategy)
	// Purpose:    Implementation of SPHSolver::SetUpdateGridStrategy()
	// Parameters:
	// - updateGridStrategy
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	void SetUpdateGridStrategy(UpdateGridStrategy *updateGridStrategy)
	{
		this->updateGridStrategy = updateGridStrategy;
	}

	////////////////////////////////////////////////////////////////////////
	// Name:       AbstractSPHSolver::SetCalPressureStrategy(CalPressureStrategy calPressureStrategy)
	// Purpose:    Implementation of AbstractSPHSolver::SetCalPressureStrategy()
	// Parameters:
	// - calPressureStrategy
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	void SetCalPressureStrategy(CalPressureStrategy *calPressureStrategy)
	{
		this->calPressureStrategy = calPressureStrategy;
	}

	////////////////////////////////////////////////////////////////////////
	// Name:       AbstractSPHSolver::SetRelaxPosStrategy(RelaxPosStrategy relaxPosStrategy)
	// Purpose:    Implementation of AbstractSPHSolver::SetRelaxPosStrategy()
	// Parameters:
	// - relaxPosStrategy
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	void SetRelaxPosStrategy(RelaxPosStrategy *relaxPosStrategy)
	{
		this->relaxPosStrategy = relaxPosStrategy;
	}

	////////////////////////////////////////////////////////////////////////
	// Name:       AbstractSPHSolver::SetCollisionStrategy(CollisionStrategy collisionStrategy)
	// Purpose:    Implementation of AbstractSPHSolver::SetCollisionStrategy()
	// Parameters:
	// - collisionStrategy
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	void SetCollisionStrategy(CollisionStrategy *collisionStrategy)
	{
		this->collisionStrategy = collisionStrategy;
	}

	////////////////////////////////////////////////////////////////////////
	// Name:       AbstractSPHSolver::SetRenderSPHStrategy(RenderSPHStrategy renderSPHStrategy)
	// Purpose:    Implementation of AbstractSPHSolver::SetRenderSPHStrategy()
	// Parameters:
	// - renderSPHStrategy
	// Return:     void
	////////////////////////////////////////////////////////////////////////
	void SetRenderSPHStrategy(RenderSPHStrategy *renderSPHStrategy)
	{
		this->renderSPHStrategy = renderSPHStrategy;
	}

	virtual void Emit() = 0;
	virtual void BodyForce() = 0;
	virtual void UpdateGrid() = 0;
	virtual void CalPressure() = 0;
	virtual void RelaxPos() = 0;
	virtual void Collision() = 0;
	virtual void RenderInit() = 0;
	void RenderSPH(bool guiOn, int i)
	{
		if (guiOn)
		{
			Display();
		}
		else
		{
			SaveResults(m_rstname, i);
		}
	}

	static std::string m_rstname;

	EmitStrategy *emitStrategy;
	BodyForceStrategy *bodyForceStrategy;
	UpdateGridStrategy *updateGridStrategy;
	CalPressureStrategy *calPressureStrategy;
	RelaxPosStrategy *relaxPosStrategy;
	CollisionStrategy *collisionStrategy;
	RenderSPHStrategy *renderSPHStrategy;

protected:
	int curParticleNum;
	int totalParticleNum;
	float dt;
	std::string scene;

private:
	virtual void Display() = 0;
	virtual void SaveResults(std::string rstname, int i) = 0;
};

class AbstractSPHSolverWrap : public AbstractSPHSolver, public wrapper<AbstractSPHSolver>
{
public:
	void SetScene(std::string fileName)
	{
		this->get_override("SetScene")(fileName);
	}
	void SolverInitSPH(float dt, int particleNum)
	{
		this->get_override("SolverInitSPH")(dt, particleNum);
	}

	void Emit()
	{
		this->get_override("Emit")();
	}
	void BodyForce()
	{
		this->get_override("BodyForce")();
	}
	void UpdateGrid()
	{
		this->get_override("UpdateGrid")();
	}
	void CalPressure()
	{
		this->get_override("CalPressure")();
	}
	void RelaxPos()
	{
		this->get_override("RelaxPos")();
	}
	void Collision()
	{
		this->get_override("Collision")();
	}
	void RenderInit()
	{
		this->get_override("RenderInit")();
	}
	void RenderSPH()
	{
		this->get_override("RenderSPH")();
	}

	static void ExportClass()
	{
		class_<AbstractSPHSolverWrap, boost::noncopyable>("AbstractSPHSolver")
			.def("SetScene", &AbstractSPHSolver::SetScene)
			.def("SolverInitSPH", &AbstractSPHSolver::SolverInitSPH)
			.def("SetEmitStrategy", &AbstractSPHSolver::SetEmitStrategy,
			with_custodian_and_ward<1, 2>())
			.def("SetBodyForceStrategy", &AbstractSPHSolver::SetBodyForceStrategy, 
			with_custodian_and_ward<1, 2>())
			.def("SetUpdateGridStrategy", &AbstractSPHSolver::SetUpdateGridStrategy, 
			with_custodian_and_ward<1, 2>())
			.def("SetCalPressureStrategy", &AbstractSPHSolver::SetCalPressureStrategy, 
			with_custodian_and_ward<1, 2>())
			.def("SetRelaxPosStrategy", &AbstractSPHSolver::SetRelaxPosStrategy, 
			with_custodian_and_ward<1, 2>())
			.def("SetCollisionStrategy", &AbstractSPHSolver::SetCollisionStrategy, 
			with_custodian_and_ward<1, 2>())
			.def("SetRenderSPHStrategy", &AbstractSPHSolver::SetRenderSPHStrategy, 
			with_custodian_and_ward<1, 2>())
			.def("Emit", pure_virtual(&AbstractSPHSolver::Emit))
			.def("BodyForce", pure_virtual(&AbstractSPHSolver::BodyForce))
			.def("UpdateGrid", pure_virtual(&AbstractSPHSolver::UpdateGrid))
			.def("CalPressure", pure_virtual(&AbstractSPHSolver::CalPressure))
			.def("RelaxPos", pure_virtual(&AbstractSPHSolver::RelaxPos))
			.def("Collision", pure_virtual(&AbstractSPHSolver::Collision))
			.def("RenderInit", pure_virtual(&AbstractSPHSolver::RenderInit))
			.def("RenderSPH", &AbstractSPHSolver::RenderSPH)
			.add_static_property("m_rstname",
			make_getter(&AbstractSPHSolver::m_rstname),
			make_setter(&AbstractSPHSolver::m_rstname));
	}

private:
	void Display()
	{
		this->get_override("Display")();
	}
	void SaveResults(std::string rstname, int i)
	{
		this->get_override("SaveResults")(rstname, i);
	}
};

#endif