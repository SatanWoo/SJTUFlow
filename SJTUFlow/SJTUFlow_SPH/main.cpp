#include "SPHSolver.h"

BOOST_PYTHON_MODULE(SJTUFlow_SPH)
{
	using namespace boost::python;

	class_<vec2>("vec2", init<>())
		.def(init<float, float>())
		.def_readwrite("x", &vec2::x)
		.def_readwrite("y", &vec2::y);

	EmitStrategyWrap::ExportClass();
	EmitA::ExportClass();

	BodyForceStrategyWrap::ExportClass();
	BodyForceA::ExportClass();

	UpdateGridStrategyWrap::ExportClass();
	UpdateGridA::ExportClass();

	CalPressureStrategyWrap::ExportClass();
	CalPressureA::ExportClass();

	RelaxPosStrategyWrap::ExportClass();
	RelaxPosA::ExportClass();

	CollisionStrategyWrap::ExportClass();
	CollisionA::ExportClass();

	RenderSPHStrategyWrap::ExportClass();
	RenderSPHA::ExportClass();

	SPHSolver::ExportClass();
}