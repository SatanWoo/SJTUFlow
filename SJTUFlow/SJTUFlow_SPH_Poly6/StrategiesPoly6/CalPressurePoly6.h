//
//  CalPressurePoly6.h
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#ifndef __water_SPH2D__CalPressurePoly6__
#define __water_SPH2D__CalPressurePoly6__

#include <iostream>

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/CalPressureStrategy.h"

#define DENSITY         0.0f
#define GAS_CONSTANT    1.0f

class CalPressurePoly6 : public CalPressureStrategy
{
public:
    void CalPressure(int particleNum, AbstractParticle** particles);

	static CalPressureStrategy * Create();

	static void ExportClass();
protected:
private:
};

#endif /* defined(__water_SPH2D__CalPressurePoly6__) */
