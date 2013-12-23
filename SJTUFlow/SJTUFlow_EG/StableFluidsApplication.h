#ifndef _STABLEFLUIDSAPPLICATION_H
#define _STABLEFLUIDSAPPLICATION_H

#include <iostream>
#include "StableFluids.h"
#include "EulerGrid.h"

using namespace std;

class StableFluidsApplication
{
public:
	StableFluidsApplication(){}
	StableFluidsApplication(int size, float timeStep, float diff);
	~StableFluidsApplication();
    
    void initialize();
    
	void setAdvectStrategy(AdvectStrategy* as) {m_as = as;}
	void setDiffuseStrategy(DiffuseStrategy* ds) {m_ds = ds;}
	void setProjectStrategy(ProjectStrategy* ps) {m_ps = ps;}
    void setAddSourceStrategY(AddSourceStrategy *ass) {m_ass = ass;}
    
    void advectVelocity();
    void advectDensity();
    
    void diffuseVelocity();
    void diffuseDensity();
    
    void projectVelocity();
    
    void addSourceVelocity();
    void addSourceDensity();

	void render();
	static void ExportClass();
    
    EulerGrid2D *grid;

private:
	AdvectStrategy *m_as;
	DiffuseStrategy *m_ds;
	ProjectStrategy *m_ps;
    AddSourceStrategy *m_ass;

    int m_size;
	float m_time;
	float m_diff;
};

#endif