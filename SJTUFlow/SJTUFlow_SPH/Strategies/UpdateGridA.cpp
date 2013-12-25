/***********************************************************************
 * Module:  UpdateGridA.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class UpdateGridA
 ***********************************************************************/

#include "UpdateGridA.h"

////////////////////////////////////////////////////////////////////////
// Name:       UpdateGridA::UpdateGrid(int particleNum, Particle* particles)
// Purpose:    Implementation of UpdateGridA::UpdateGrid()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////

void UpdateGridA::UpdateGrid(int particleNum, Particle* particles)
{
	// TODO : implement
	memset(grid, 0, kGridCellCount*sizeof(Particle*));
    // Add particles to grid
    for (size_t i=0; i<particleNum; ++i){
        Particle& pi = particles[i];
        int x = pi.curPos.x / kCellSize;
        int y = pi.curPos.y / kCellSize;

        if (x < 1)
            x = 1;
        else if (x > kGridWidth-2)
            x = kGridWidth-2;

        if (y < 1)
            y = 1;
        else if (y > kGridHeight-2)
            y = kGridHeight-2;

        pi.next = grid[x+y*kGridWidth];
        grid[x+y*kGridWidth] = &pi;

        gridCoords[i*2] = x;
        gridCoords[i*2+1] = y;
    }

    for (size_t i=0; i<particleNum; ++i){
        Particle& pi = particles[i];
        size_t gi = gridCoords[i*2];
        size_t gj = gridCoords[i*2+1]*kGridWidth;

        pi.neighbour_count = 0;
        for (size_t ni=gi-1; ni<=gi+1; ++ni){
            for (size_t nj=gj-kGridWidth; nj<=gj+kGridWidth; nj+=kGridWidth){
                for (Particle* ppj=grid[ni+nj]; NULL!=ppj; ppj=ppj->next){
                    const Particle& pj = *ppj;

                    float dx = pj.curPos.x - pi.curPos.x;
                    float dy = pj.curPos.y - pi.curPos.y;
                    float r2 = dx*dx + dy*dy;
                    if (r2 < kEpsilon2 || r2 > kH*kH)
                        continue;

                    float r = sqrt(r2);
                    if (pi.neighbour_count < kMaxNeighbourCount){
                        pi.neighbours[pi.neighbour_count] = pj.index;
                        pi.r[pi.neighbour_count] = r;
                        ++pi.neighbour_count;
                    }
                }
            }
        }
    }
}

UpdateGridStrategy * UpdateGridA::Create()
{
	return new UpdateGridA;
}

void UpdateGridA::ExportClass()
{
	class_<UpdateGridA, bases<UpdateGridStrategy> >("UpdateGridA", init<>())
		.def("UpdateGrid", &UpdateGridA::UpdateGrid)
		.def("Create", &UpdateGridA::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}
