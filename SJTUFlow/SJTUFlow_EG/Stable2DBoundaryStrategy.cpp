#include "Stable2DBoundaryStrategy.h"
#include "Utility.h"

void Stable2DBoundaryStrategy::setUpBoundary(int size, BoundaryType type, float *boundary)
{
	int i;
	int N = size;

	for ( i=1 ; i<=N ; i++ ) {
		boundary[IX(0  ,i)] = type==BounadaryTypeHorizontal ? -boundary[IX(1,i)] : boundary[IX(1,i)]; // horizontal
		boundary[IX(N+1,i)] = type==BounadaryTypeHorizontal ? -boundary[IX(N,i)] : boundary[IX(N,i)];
		boundary[IX(i,0  )] = type==BounadaryTypeVertical ? -boundary[IX(i,1)] : boundary[IX(i,1)]; // vertical
		boundary[IX(i,N+1)] = type==BounadaryTypeVertical ? -boundary[IX(i,N)] : boundary[IX(i,N)];
	}

	boundary[IX(0  ,0  )] = 0.5f*(boundary[IX(1,0  )]+boundary[IX(0  ,1)]);
	boundary[IX(0  ,N+1)] = 0.5f*(boundary[IX(1,N+1)]+boundary[IX(0  ,N)]);
	boundary[IX(N+1,0  )] = 0.5f*(boundary[IX(N,0  )]+boundary[IX(N+1,1)]);
	boundary[IX(N+1,N+1)] = 0.5f*(boundary[IX(N,N+1)]+boundary[IX(N+1,N)]);
}

BoundaryStrategy * Stable2DBoundaryStrategy::Create()
{
	return new Stable2DBoundaryStrategy;
}

void Stable2DBoundaryStrategy::ExportClass()
{
	class_<Stable2DBoundaryStrategy, bases<BoundaryStrategy>>("Stable2DBoundaryStrategy", init<>())
		.def("setUpBoundary", &Stable2DBoundaryStrategy::setUpBoundary)
		.def("Create", &Stable2DBoundaryStrategy::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
