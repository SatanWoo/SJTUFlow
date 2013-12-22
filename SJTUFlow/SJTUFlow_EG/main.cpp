#include "StableFluidsApplication.h"

#include "Stable2DAdvectStrategy.h"
#include "Stable2DDiffuseStrategy.h"
#include "Stable2DProjectStrategy.h"
#include "Stable2DBoundaryStrategy.h"
#include "Stable2DAddSourceStrategy.h"

BOOST_PYTHON_MODULE(SJTUFlow_EG)
{
	EulerGrid2D::ExportClass();

	AdvectStrategyWrap::ExportClass();
	Stable2DAdvectStrategy::ExportClass();

	DiffuseStrategyWrap::ExportClass();
	Stable2DDiffuseStrategy::ExportClass();

	ProjectStrategyWrap::ExportClass();
	Stable2DProjectStrategy::ExportClass();

	BoundaryStrategyWrap::ExportClass();
	Stable2DBoundaryStrategy::ExportClass();

	AddSourceStrategyWrap::ExportClass();
	Stable2DAddSourceStrategy::ExportClass();

	StableFluidsApplication::ExportClass();
}