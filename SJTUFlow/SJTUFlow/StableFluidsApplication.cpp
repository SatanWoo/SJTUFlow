#include "StableFluidsApplication.h"
#include "Utility.h"

StableFluidsApplication::StableFluidsApplication(int size, int timeStep, float diff):m_size(size), m_time(timeStep), m_diff(diff)
{}

StableFluidsApplication::~StableFluidsApplication()
{
	if (u)			free(u);
	if (v)			free(v);
	if (prevU)		free(prevU);
	if (prevV)		free(prevV);
	if (density)	free(density);
	if (preDensity) free(preDensity);
}

void StableFluidsApplication::simulateDensity()
{
	addSource(density, preDensity);
	SWAP(preDensity, density);

	float a = m_time * m_diff * m_size * m_size;
	gaussSiedelIteration(BounadaryTypeNone, density, preDensity, a, 1+4*a);

	SWAP(preDensity, density);

	m_as->advect(m_size, BounadaryTypeNone, density, preDensity, u, v, m_time);
	m_bs->setUpBoundary(m_size, BounadaryTypeNone, density);
}

void StableFluidsApplication::simulateVelocity()
{
	addSource(u, prevU);addSource(v, prevV);
	float a = m_time * m_diff * m_size * m_size;
	
	SWAP(prevU, u);gaussSiedelIteration(BounadaryTypeNone, u, prevU, a, 1+4*a);
	SWAP(prevV, v);gaussSiedelIteration(BounadaryTypeNone, v, prevV, a, 1+4*a);

	m_ps->projectStepOne(m_size, u, v, prevU, prevV);
	m_bs->setUpBoundary(m_size, BounadaryTypeNone, prevV);
	m_bs->setUpBoundary(m_size, BounadaryTypeNone, prevU);
	gaussSiedelIteration(BounadaryTypeNone, u, prevU, 1, 4);

	m_ps->projectStepTwo(m_size, u, v, prevU, prevV);
	m_bs->setUpBoundary(m_size, BounadaryTypeHorizontal, u);
	m_bs->setUpBoundary(m_size, BounadaryTypeVertical, v);

	SWAP(prevU, u); SWAP(prevV, v);

	m_as->advect(m_size, BounadaryTypeHorizontal, u, prevU, prevU, prevV, m_time);
	m_bs->setUpBoundary(m_size, BounadaryTypeHorizontal, u);
	m_as->advect(m_size, BounadaryTypeVertical, v, prevV, prevU, prevV, m_time);
	m_bs->setUpBoundary(m_size, BounadaryTypeVertical, v);

	m_ps->projectStepOne(m_size, u, v, prevU, prevV);
	m_bs->setUpBoundary(m_size, BounadaryTypeNone, prevV);
	m_bs->setUpBoundary(m_size, BounadaryTypeNone, prevU);
	gaussSiedelIteration(BounadaryTypeNone, u, prevU, 1, 4);

	m_ps->projectStepTwo(m_size, u, v, prevU, prevV);
	m_bs->setUpBoundary(m_size, BounadaryTypeHorizontal, u);
	m_bs->setUpBoundary(m_size, BounadaryTypeVertical, v);
}

void StableFluidsApplication::gaussSiedelIteration(BounadaryType type, float *current, float *old, float a, float c)
{
	int i, j, k;
	int N  = m_size;

	for ( k=0 ; k<20 ; k++ ) {
		FOR_EACH_CELL
			current[IX(i,j)] = (old[IX(i,j)] + a*(current[IX(i-1,j)]+current[IX(i+1,j)]+current[IX(i,j-1)]+current[IX(i,j+1)]))/c;
		END_FOR
			this->m_bs->setUpBoundary( N, type, current);
	}
}

void StableFluidsApplication::addSource(float *current, float *old)
{
	int i, size=(m_size + 2) * (m_size + 2);
	for ( i=0 ; i<size ; i++ ) current[i] += m_time * old[i];
}
