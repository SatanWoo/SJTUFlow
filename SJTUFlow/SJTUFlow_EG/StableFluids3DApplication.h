//
//  StableFluids3DApplication.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-20.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_StableFluids3DApplication_h
#define Eulter_SE_StableFluids3DApplication_h

#include "EulerGrid.h"
#include "StableFluids.h"

#include "../SJTUFlow_Global/EulerApplication.h"

class StableFluids3DApplication : public EulerApplication
{
public:
    StableFluids3DApplication(int size, float timeStep, float diff);
    ~StableFluids3DApplication();
    
    virtual void initialize();
    
    virtual void advectVelocity();
    virtual void advectDensity();

    virtual void diffuseVelocity();
    virtual void diffuseDensity();

    virtual void projectVelocity();

    virtual void addSourceVelocity();
    virtual void addSourceDensity();

	static void ExportClass();
    
    EulerGrid3D *grid;

private:
	void display();
	void saveResults(string rstname, int i);
};

#endif
