//
//  SPHSolver.h
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#ifndef __water_SPH2D__SPHSolver__
#define __water_SPH2D__SPHSolver__

#include <iostream>
#include "utils.h"
#include "Particle.h"

#include "../SJTUFlow_Global/AbstractSPHSolver.h"

class SPHPoly6Solver : public AbstractSPHSolver
{
public:
	SPHPoly6Solver();
    void SetScene(std::string fileName);
    void SolverInitSPH(float density, int particleNum);
    void Emit(void);
    void BodyForce(void);
    void UpdateGrid(void);
    void CalPressure(void);
    void RelaxPos(void);
    void Collision(void);
    void RenderInit(void);

	static void ExportClass();

protected:
    
private:
    void addRect(Vector2f center, float width, float height);
    void addCir(Vector2f center, float radiuso);
    void updateObjectGrid();

	void Display();
	void SaveResults(std::string rstname, int i);

	void ParseScene(std::string fileName);
    
	Particle particles[PARTICLE_COUNT];
    AbstractParticle* particlesArray[PARTICLE_COUNT];
	float density;
};

#endif /* defined(__water_SPH2D__SPHSolver__) */
