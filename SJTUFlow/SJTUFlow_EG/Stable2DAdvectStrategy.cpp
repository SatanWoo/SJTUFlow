#include "Stable2DAdvectStrategy.h"
#include "Utility.h"
#include "MathHelper.h"

void Stable2DAdvectStrategy::advect(int N, BoundaryType type, float *d, float *d0, float *u, float *v, float dt)
{
	int i, j, i0, j0, i1, j1;
	float x, y, s0, t0, s1, t1, dt0;
    
	dt0 = dt * N;
	FOR_EACH_CELL
    
    x = i - dt0 * u[IX(i,j)]; y = j - dt0 * v[IX(i,j)];
    if (x < 0.5f) x = 0.5f; if (x > N + 0.5f) x = N + 0.5f; i0 = (int)x; i1 = i0 + 1;
    if (y < 0.5f) y = 0.5f; if (y > N + 0.5f) y = N + 0.5f; j0 = (int)y; j1 = j0 + 1; // 设置边界
    
    s1 = x - i0; s0 = 1 - s1; t1 = y - j0; t0 = 1 - t1;// 插值系数
    d[IX(i,j)] = s0 * (t0 * d0[IX(i0,j0)] + t1 * d0[IX(i0,j1)]) + s1 * (t0 * d0[IX(i1,j0)] + t1 * d0[IX(i1,j1)]);// d0 predensity
    
	END_FOR
}

AdvectStrategy * Stable2DAdvectStrategy::Create()
{
	return new Stable2DAdvectStrategy;
}

void Stable2DAdvectStrategy::ExportClass()
{
	class_<Stable2DAdvectStrategy, bases<AdvectStrategy>>("Stable2DAdvectStrategy", init<>())
		.def("advect", &Stable2DAdvectStrategy::advect)
		.def("Create", &Stable2DAdvectStrategy::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
