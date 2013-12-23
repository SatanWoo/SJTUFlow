#include "Stable2DProjectStrategy.h"
#include "Utility.h"
#include "MathHelper.h"

Stable2DProjectStrategy::Stable2DProjectStrategy(BoundaryStrategy *bs)
{
    m_bs = bs;
}

void Stable2DProjectStrategy::project(int N, float * u, float * v, float * p, float * div)
{
    int i, j;
    
	FOR_EACH_CELL
    div[IX(i,j)] = -0.5f*(u[IX(i+1,j)]-u[IX(i-1,j)]+v[IX(i,j+1)]-v[IX(i,j-1)])/N;
    p[IX(i,j)] = 0;
	END_FOR
    
    m_bs->setBoundary(N, BoundaryTypeNone, div);
    m_bs->setBoundary(N, BoundaryTypeNone, p);
    
    MathHelper::linearCalculation( N, BoundaryTypeNone, p, div, 1, 4 );
    
	FOR_EACH_CELL
    u[IX(i,j)] -= 0.5f*N*(p[IX(i+1,j)]-p[IX(i-1,j)]);
    v[IX(i,j)] -= 0.5f*N*(p[IX(i,j+1)]-p[IX(i,j-1)]);
	END_FOR
    
    m_bs->setBoundary(N, BoundaryTypeU, u);
    m_bs->setBoundary(N, BoundaryTypeV, v);
}

ProjectStrategy * Stable2DProjectStrategy::Create( BoundaryStrategy *bs )
{
	return new Stable2DProjectStrategy(bs);
}

void Stable2DProjectStrategy::ExportClass()
{
	class_<Stable2DProjectStrategy, bases<ProjectStrategy>>("Stable2DProjectStrategy", init<>())
		.def("project", &Stable2DProjectStrategy::project)
		.def("Create", &Stable2DProjectStrategy::Create, 
		return_value_policy<manage_new_object>(), with_custodian_and_ward<1, 2>())
		.staticmethod("Create");
}

