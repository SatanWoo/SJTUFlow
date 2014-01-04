//
//  UpdateGridPoly6.cpp
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#include "UpdateGridPoly6.h"

void UpdateGridPoly6::UpdateGrid(int particleNum, AbstractParticle** particles)
{
    memset(grid, NULL, GRID_SIZE * sizeof(Particle*));
    
    for (size_t i = 0; i < particleNum; i++) {
        Particle* p = (Particle*)particles[i];
        int x = p->curPos.x * GRID_WIDTH;
        int y = p->curPos.y * GRID_HEIGHT;
        
        if (x < 1)
        {
            x = 1;
        }
        else if (x > GRID_WIDTH - 2)
        {
            x = GRID_WIDTH - 2;
        }
        
        if ( y < 1)
        {
            y = 1;
        }
        else if (y > GRID_HEIGHT- 2)
        {
            y = GRID_HEIGHT - 2;
        }
        
        p->next = grid[x + y * GRID_WIDTH];
        grid[x + y * GRID_WIDTH] = p;
        
        p->gridCords.x = x;
        p->gridCords.y = y;
    }
    
    for (size_t i = 0; i < particleNum; i++) {
        Particle* pi = (Particle*)particles[i];
        size_t gi = pi->gridCords.x;
        size_t gj = pi->gridCords.y * GRID_WIDTH;
        
        pi->neighbour_count = 0;
        
        for (size_t ni = gi - 1; ni <= gi + 1; ni++) {
            for (size_t nj = gj - GRID_WIDTH; nj <= gj + GRID_WIDTH; nj += GRID_WIDTH) {
                for (Particle* ppo = grid_object[ni + nj]; ppo != NULL; ppo = ppo->next) {
                    const Particle* pj = ppo;
                    
                    float dx = pi->curPos.x - pj->curPos.x;
                    float dy = pi->curPos.y - pj->curPos.y;
                    float r2 = dx * dx + dy * dy;
                    if(r2 < EPSILON2 || r2 > DISTANCE2)
                    {
                        continue;
                    }
                    
                    float r = sqrtf(r2);
                    
                    if (pi->neighbour_count < NEIGHBOURS_MAX_COUNT)
                    {
                        pi->neighbours[pi->neighbour_count] = pj;
                        pi->distance_neighbours[pi->neighbour_count] = r;
                        pi->neighbour_count++;
                    }
                    
                    if(ppo->neighbour_count < NEIGHBOURS_MAX_COUNT)
                    {
                        ppo->neighbours[ppo->neighbour_count] = pi;
                        ppo->distance_neighbours[ppo->neighbour_count] = r;
                        ppo->neighbour_count++;
                    }
                }
            }
        }
        
        for (size_t ni = gi - 1; ni <= gi + 1; ni++) {
            for (size_t nj = gj - GRID_WIDTH; nj <= gj + GRID_WIDTH; nj += GRID_WIDTH) {
                for (Particle* ppj = grid[ni + nj]; ppj != NULL; ppj = ppj->next) {
                    const Particle* pj = ppj;
                    
                    float dx = pi->curPos.x - pj->curPos.x;
                    float dy = pi->curPos.y - pj->curPos.y;
                    float r2 = dx * dx + dy * dy;
                    if(r2 < EPSILON2 || r2 > DISTANCE2)
                    {
                        continue;
                    }
                    
                    float r = sqrtf(r2);
                    
                    if (pi->neighbour_count < NEIGHBOURS_MAX_COUNT)
                    {
                        pi->neighbours[pi->neighbour_count] = pj;
                        pi->distance_neighbours[pi->neighbour_count] = r;
                        pi->neighbour_count++;
                    }
                }
            }
        }
    }
}

UpdateGridStrategy * UpdateGridPoly6::Create()
{
	return new UpdateGridPoly6;
}

void UpdateGridPoly6::ExportClass()
{
	class_<UpdateGridPoly6, bases<UpdateGridStrategy> >("UpdateGridPoly6", init<>())
		.def("UpdateGrid", &UpdateGridPoly6::UpdateGrid)
		.def("Create", &UpdateGridPoly6::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
