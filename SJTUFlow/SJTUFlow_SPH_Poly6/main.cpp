#include "SPHSolver.h"
#include "StrategiesPoly6/StrategiesPoly6.h"

std::string StaticVaribles::m_rstname = "";
std::string StaticVaribles::m_scname = "";

BOOST_PYTHON_MODULE(SJTUFlow_SPH_Poly6)
{
	using namespace boost::python;

	EmitStrategyWrap::ExportClass();
	EmitPoly6::ExportClass();

	BodyForceStrategyWrap::ExportClass();
	BodyForcePoly6::ExportClass();

	UpdateGridStrategyWrap::ExportClass();
	UpdateGridPoly6::ExportClass();

	CalPressureStrategyWrap::ExportClass();
	CalPressurePoly6::ExportClass();

	RelaxPosStrategyWrap::ExportClass();
	RelaxPosPoly6::ExportClass();

	CollisionStrategyWrap::ExportClass();
	CollisionPoly6::ExportClass();

	RenderSPHStrategyWrap::ExportClass();
	RenderSPHPoly6::ExportClass();

	SPHPoly6Solver::ExportClass();
}