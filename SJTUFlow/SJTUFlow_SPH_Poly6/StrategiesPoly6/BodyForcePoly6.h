//
//  BodyForcePoly6.h
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#ifndef __water_SPH2D__BodyForcePoly6__
#define __water_SPH2D__BodyForcePoly6__

#include <iostream>

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/BodyForceStrategy.h"

#define GRAVITY -0.0000098f
#define P_CORRECT   0.0000055f
#define VISCOSITY   0.004f

#define P_CORRECT_OBJECT   P_CORRECT * 20
#define VISCOSITY_OBJECT   VISCOSITY * 20

class BodyForcePoly6 : public BodyForceStrategy
{
public:
	void ApplyBodyForce(int particleNum, float density,AbstractParticle** particles);

	static BodyForceStrategy* Create();

	static void ExportClass();
protected:
private:
};

#endif /* defined(__water_SPH2D__BodyForcePoly6__) */
