//
//  StableFluids3DApplication.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-20.
//  Copyright (c) 2013年 Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_StableFluids3DApplication_h
#define Eulter_SE_StableFluids3DApplication_h

#include "EulerGrid.h"
#include "StableFluids.h"

class StableFluids3DApplication
{
public:
    StableFluids3DApplication(int size, float timeStep, float diff);
    ~StableFluids3DApplication();
    
    void setAdvectStrategy(Advect3DStrategy* as) {m_as = as;}
	void setDiffuseStrategy(DiffuseStrategy* ds) {m_ds = ds;}
	void setProjectStrategy(Project3DStrategy* ps) {m_ps = ps;}
    void setAddSourceStrategY(AddSourceStrategy *ass) {m_ass = ass;}
    
    void initialize();
    
    void advectVelocity();
    void advectDensity();
    
    void diffuseVelocity();
    void diffuseDensity();
    
    void projectVelocity();
    
    void addSourceVelocity();
    void addSourceDensity();

	void render();
	static void ExportClass();
    
    EulerGrid3D *grid;
    
private:
    Advect3DStrategy *m_as;
	DiffuseStrategy *m_ds;
	Project3DStrategy *m_ps;
    AddSourceStrategy *m_ass;
    
    int m_size;
	float m_time;
	float m_diff;
};

#endif
