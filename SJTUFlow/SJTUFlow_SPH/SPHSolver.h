/***********************************************************************
 * Module:  SPHSolver.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:54
 * Purpose: Declaration of the class SPHSolver
 ***********************************************************************/

#if !defined(__SJTUFLOW2_SPHSolver_h)
#define __SJTUFLOW2_SPHSolver_h

#include "EmitStrategy.h"
#include "BodyForceStrategy.h"
#include "UpdateGridStrategy.h"
#include "CalPressureStrategy.h"
#include "RelaxPosStrategy.h"
#include "CollisionStrategy.h"
#include "RenderSPHStrategy.h"

#include "utils.h"
#include <iostream>

class SPHSolver
{
public:
	SPHSolver();
	void SetScene(std::string fileName);
	void SolverDestroy(void);
	void SolverInitSPH(vec2 gs, float dt, int particleNum);
	void SetEmitStrategy(EmitStrategy *emitStrategy);
	void SetBodyForceStrategy(BodyForceStrategy *bodyForceStrategy);
	void SetUpdateGridStrategy(UpdateGridStrategy *updateGridStrategy);
	void SetCalPressureStrategy(CalPressureStrategy *calPressureStrategy);
	void SetRelaxPosStrategy(RelaxPosStrategy *relaxPosStrategy);
	void SetCollisionStrategy(CollisionStrategy *collisionStrategy);
	void SetRenderSPHStrategy(RenderSPHStrategy *renderSPHStrategy);
	void Emit(void);
	void BodyForce(void);
	void UpdateGrid(void);
	void CalPressure(void);
	void RelaxPos(void);
	void Collision(void);
	void RenderInit(void);
	void RenderSPH(void);
	
	static void ExportClass();

	EmitStrategy *emitStrategy;
	BodyForceStrategy *bodyForceStrategy;
	UpdateGridStrategy *updateGridStrategy;
	CalPressureStrategy *calPressureStrategy;
	RelaxPosStrategy *relaxPosStrategy;
	CollisionStrategy *collisionStrategy;
	RenderSPHStrategy *renderSPHStrategy;

protected:
private:
    int curParticleNum;
    int totalParticleNum;
    Particle particles[kParticleCount];
    float dt;
    std::string scene;
};

#endif
