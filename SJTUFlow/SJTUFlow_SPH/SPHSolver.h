/***********************************************************************
 * Module:  SPHSolver.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:54
 * Purpose: Declaration of the class SPHSolver
 ***********************************************************************/

#if !defined(__SJTUFLOW2_SPHSolver_h)
#define __SJTUFLOW2_SPHSolver_h

#include "../SJTUFlow_Global/AbstractSPHSolver.h"

#include "utils.h"
#include <iostream>

class SPHSolver : public AbstractSPHSolver
{
public:
	SPHSolver();
	virtual void SetScene(std::string fileName);
	virtual void SolverInitSPH(float dt, int particleNum);
	virtual void Emit(void);
	virtual void BodyForce(void);
	virtual void UpdateGrid(void);
	virtual void CalPressure(void);
	virtual void RelaxPos(void);
	virtual void Collision(void);
	virtual void RenderInit(void);
	
	static void ExportClass();
protected:
private:
    AbstractParticle* particles[kParticleCount];

	virtual void Display();
	virtual void SaveResults(std::string rstname, int i);
};

#endif
