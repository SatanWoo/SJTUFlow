//
//  UpdateGridPoly6.h
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#ifndef __water_SPH2D__UpdateGridPoly6__
#define __water_SPH2D__UpdateGridPoly6__

#include <iostream>

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/UpdateGridStrategy.h"

class UpdateGridPoly6 : public UpdateGridStrategy
{
public:
    void UpdateGrid(int particleNum, AbstractParticle** particles);

	static UpdateGridStrategy * Create();

	static void ExportClass();
protected:
private:
    Particle* grid[GRID_SIZE];
};

#endif /* defined(__water_SPH2D__UpdateGridPoly6__) */
