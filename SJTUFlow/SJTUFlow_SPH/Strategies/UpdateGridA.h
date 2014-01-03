/***********************************************************************
 * Module:  UpdateGridA.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class UpdateGridA
 ***********************************************************************/

#if !defined(__SJTUFLOW2_UpdateGridA_h)
#define __SJTUFLOW2_UpdateGridA_h

#include "../utils.h"
#include "../Particle.h"
#include "../SJTUFlow_Global/UpdateGridStrategy.h"

#define kEpsilon 0.0000001f
#define kEpsilon2 (kEpsilon*kEpsilon)
#define kCellSize kH
const size_t kGridWidth = (size_t)(kViewWidth / kCellSize);
const size_t kGridHeight = (size_t)(kViewHeight / kCellSize);
const size_t kGridCellCount = kGridWidth * kGridHeight;

class UpdateGridA : public UpdateGridStrategy
{
public:
	void UpdateGrid(int particleNum, AbstractParticle** particles);

	static UpdateGridStrategy *Create();
	static void ExportClass();

protected:
private:
    Particle* grid[kGridCellCount];
    size_t gridCoords[kParticleCount*2];
};

#endif
