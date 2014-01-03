#include "SPHSolver.h"
#include "Strategies.h"

std::string AbstractSPHSolver::m_rstname = "";

BOOST_PYTHON_MODULE(SJTUFlow_SPH)
{
	using namespace boost::python;

	class_<vector2>("vector2", init<>())
		.def(init<float, float>())
		.def_readwrite("x", &vector2::x)
		.def_readwrite("y", &vector2::y);

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