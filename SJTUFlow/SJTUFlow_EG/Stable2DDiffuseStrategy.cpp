#include "Stable2DDiffuseStrategy.h"
#include "MathHelper.h"


void Stable2DDiffuseStrategy::diffuse(int N, BoundaryType b, float * x, float * x0, float diff, float dt)
{
	float a = dt * diff * N * N;
    MathHelper::linearCalculation(N, b, x, x0, diff, 1+4*a);
}

DiffuseStrategy * Stable2DDiffuseStrategy::Create()
{
	return new Stable2DDiffuseStrategy;
}

void Stable2DDiffuseStrategy::ExportClass()
{
	class_<Stable2DDiffuseStrategy, bases<DiffuseStrategy>>("Stable2DDiffuseStrategy", init<>())
		.def("diffuse", &Stable2DDiffuseStrategy::diffuse)
		.def("Create", &Stable2DDiffuseStrategy::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
