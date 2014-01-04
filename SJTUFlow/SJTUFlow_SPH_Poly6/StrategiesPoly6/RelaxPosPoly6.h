//
//  RelaxPosPoly6.h
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#ifndef __water_SPH2D__RelaxPosPoly6__
#define __water_SPH2D__RelaxPosPoly6__

#include <iostream>

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/RelaxPosStrategy.h"

class RelaxPosPoly6 : public RelaxPosStrategy
{
public:
    void RelaxPos(int particleNum, float density, AbstractParticle** particles);

	static RelaxPosStrategy * Create();

	static void ExportClass();
protected:
private:
};

#endif /* defined(__water_SPH2D__RelaxPosPoly6__) */
