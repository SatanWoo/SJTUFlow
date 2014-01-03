#include "global.h"
#include "EulerApplication.h"
#include "AbstractSPHSolver.h"

string EulerApplication::m_rstname = "";
string AbstractSPHSolver::m_rstname = "";

void translateUnconnectedException(const UnconnectedException &exc)
{
	PyErr_SetString(PyExc_ConnectionError, exc.msg.c_str());
}

BOOST_PYTHON_MODULE(SJTUFlow_Global)
{
	register_exception_translator<UnconnectedException>(&translateUnconnectedException);

// Euler Gird
	AdvectStrategyWrap::ExportClass();

	DiffuseStrategyWrap::ExportClass();

	ProjectStrategyWrap::ExportClass();

	BoundaryStrategyWrap::ExportClass();

	AddSourceStrategyWrap::ExportClass();

	EulerApplicationWrap::ExportClass();

// SPH
	EmitStrategyWrap::ExportClass();

	BodyForceStrategyWrap::ExportClass();

	UpdateGridStrategyWrap::ExportClass();

	CalPressureStrategyWrap::ExportClass();

	RelaxPosStrategyWrap::ExportClass();

	CollisionStrategyWrap::ExportClass();

	RenderSPHStrategyWrap::ExportClass();

	AbstractSPHSolverWrap::ExportClass();
}