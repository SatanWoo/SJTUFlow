#include "SPHSolver.h"
#include "Strategies.h"

std::string StaticVaribles::m_rstname = "";
std::string StaticVaribles::m_scname = "";

BOOST_PYTHON_MODULE(SJTUFlow_SPH)
{
	using namespace boost::python;

	EmitStrategyWrap::ExportClass();
	EmitA::ExportClass();
	EmitB::ExportClass();

	BodyForceStrategyWrap::ExportClass();
	BodyForceA::ExportClass();
	BodyForceB::ExportClass();

	UpdateGridStrategyWrap::ExportClass();
	UpdateGridA::ExportClass();
	UpdateGridB::ExportClass();

	CalPressureStrategyWrap::ExportClass();
	CalPressureA::ExportClass();
	CalPressureB::ExportClass();

	RelaxPosStrategyWrap::ExportClass();
	RelaxPosA::ExportClass();
	RelaxPosB::ExportClass();

	CollisionStrategyWrap::ExportClass();
	CollisionA::ExportClass();
	CollisionB::ExportClass();

	RenderSPHStrategyWrap::ExportClass();
	RenderSPHA::ExportClass();
	RenderSPHB::ExportClass();

	SPHSolver::ExportClass();
}