#ifndef _STABLEFLUIDSAPPLICATION_H
#define _STABLEFLUIDSAPPLICATION_H

#include <iostream>
#include "StableFluids.h"
#include "EulerGrid.h"

#include "../SJTUFlow_Global/EulerApplication.h"

using namespace std;

class StableFluidsApplication : public EulerApplication
{
public:
	StableFluidsApplication(){}
	StableFluidsApplication(int size, float timeStep, float diff);
	~StableFluidsApplication();
    
    virtual void initialize();
    
    virtual void advectVelocity();
    virtual void advectDensity();
    
    virtual void diffuseVelocity();
    virtual void diffuseDensity();

    virtual void projectVelocity();
 
    virtual void addSourceVelocity();
    virtual void addSourceDensity();

	static void ExportClass();
    
    EulerGrid2D *grid;

private:
	void display(int i);
	void saveResults(string rstname, int i);
};

#endif