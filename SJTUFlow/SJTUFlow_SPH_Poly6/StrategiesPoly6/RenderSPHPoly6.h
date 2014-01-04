//
//  RenderSPHPoly6.h
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#ifndef __water_SPH2D__RenderSPHPoly6__
#define __water_SPH2D__RenderSPHPoly6__

#include <iostream>

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/RenderSPHStrategy.h"

class RenderSPHPoly6 : public RenderSPHStrategy
{
public:
    void RenderInit();
    void RenderSPH(int particleNum, AbstractParticle** particles, std::string scene);

	static RenderSPHStrategy * Create();

	static void ExportClass();
protected:
private:
};

#endif /* defined(__water_SPH2D__RenderSPHPoly6__) */
