/***********************************************************************
 * Module:  RenderSPHA.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class RenderSPHA
 ***********************************************************************/

#if !defined(__SJTUFLOW2_RenderSPHA_h)
#define __SJTUFLOW2_RenderSPHA_h

#include "../utils.h"
#include "../Particle.h"
#include "../RenderSPHStrategy.h"

class RenderSPHA : public RenderSPHStrategy
{
public:
	static size_t _particleNum;
	static Particle *_particles;
	void Render();
	void RenderInit();
	void RenderSPH(int particleNum, Particle* particles, std::string scene);

	static RenderSPHStrategy *Create();
	static void ExportClass();
protected:
private:

};

#endif
