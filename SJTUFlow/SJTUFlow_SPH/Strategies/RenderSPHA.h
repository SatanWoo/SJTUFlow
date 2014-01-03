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
#include "../SJTUFlow_Global/RenderSPHStrategy.h"

class RenderSPHA : public RenderSPHStrategy
{
public:
	static size_t _particleNum;
	static AbstractParticle **_particles;
	void Render();
	void RenderInit();
	void RenderSPH(int particleNum, AbstractParticle** particles, std::string scene);

	static RenderSPHStrategy *Create();
	static void ExportClass();
protected:
private:

};

#endif
