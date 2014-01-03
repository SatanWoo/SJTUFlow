#include "StableFluidsApplication.h"
#include "StableFluids3DApplication.h"

#include "Stable2DAdvectStrategy.h"
#include "Stable2DDiffuseStrategy.h"
#include "Stable2DProjectStrategy.h"
#include "Stable2DBoundaryStrategy.h"
#include "Stable2DAddSourceStrategy.h"

#include "Stable3DAdvectStrategy.h"
#include "Stable3DAddSourceStrategy.h"
#include "Stable3DBoundaryStrategy.h"
#include "Stable3DDiffuseStrategy.h"
#include "Stable3DProjectStrategy.h"

string EulerApplication::m_rstname = "";

BOOST_PYTHON_MODULE(SJTUFlow_EG)
{
	EulerGrid2D::ExportClass();
	EulerGrid3D::ExportClass();

	AdvectStrategyWrap::ExportClass();
	Stable2DAdvectStrategy::ExportClass();
	Stable3DAdvectStrategy::ExportClass();

	DiffuseStrategyWrap::ExportClass();
	Stable2DDiffuseStrategy::ExportClass();
	Stable3DDiffuseStrategy::ExportClass();

	ProjectStrategyWrap::ExportClass();
	Stable2DProjectStrategy::ExportClass();
	Stable3DProjectStrategy::ExportClass();

	BoundaryStrategyWrap::ExportClass();
	Stable2DBoundaryStrategy::ExportClass();
	Stable3DBoundaryStrategy::ExportClass();

	AddSourceStrategyWrap::ExportClass();
	Stable2DAddSourceStrategy::ExportClass();
	Stable3DAddSourceStrategy::ExportClass();

	StableFluidsApplication::ExportClass();
	StableFluids3DApplication::ExportClass();
}