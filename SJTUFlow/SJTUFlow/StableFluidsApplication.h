#ifndef _STABLEFLUIDSAPPLICATION_H
#define _STABLEFLUIDSAPPLICATION_H

#include <iostream>
#include "StableFluids.h"

using namespace std;

class StableFluidsApplication
{
public:
	StableFluidsApplication(int size, int timeStep, float diff);
	~StableFluidsApplication();

	void setAdvectStrategy(AdvectStrategy* as) {m_as = as;}
	void setDiffuseStrategy(DiffuseStrategy* ds) {m_ds = ds;}
	void setProjectStrategy(ProjectStrategy* ps) {m_ps = ps;}
	void setBoundaryStrategy(BoundaryStrategy *bs) {m_bs = bs;}

	void simulateDensity();
	void simulateVelocity();

private:
	AdvectStrategy *m_as;
	DiffuseStrategy *m_ds;
	ProjectStrategy *m_ps;
	BoundaryStrategy *m_bs;

	float *u;
	float *v;
	float *prevU;
	float *prevV;
	float *density;
	float *preDensity;

	int m_size;
	int m_time;
	float m_diff;

	void gaussSiedelIteration(BounadaryType type, float *current, float *old, float a, float c);
	void addSource(float *current, float *old);
};

#endif