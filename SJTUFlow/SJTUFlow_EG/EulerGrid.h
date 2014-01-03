//
//  EulerGrid.h
//  Eulter SE
//
//  Created by satanwoo on 13-12-15.
//  Copyright (c) 2013Äê Ziqi Wu. All rights reserved.
//

#ifndef Eulter_SE_EulerGrid_h
#define Eulter_SE_EulerGrid_h

#include "Utility.h"
#include "Velocity.h"

class EulerGrid2D
{
public:
	EulerGrid2D(int size, float viscocity, float time);
	~EulerGrid2D();

	Velocity2D *getU(){return u;}
	Velocity2D *getV(){return v;}
	Velocity2D *getDensity()const{return density;}

	float getCurU(int x, int y)const {return u->getCurrent()[IX_S(x, y, m_size)];}
	float getCurV(int x, int y)const {return v->getCurrent()[IX_S(x, y, m_size)];}
	float getCurDensity(int x, int y)const {return density->getCurrent()[IX_S(x, y, m_size)];}

	float getPreU(int x, int y)const {return u->getPrevious()[IX_S(x, y, m_size)];}
	float getPreV(int x, int y)const {return v->getPrevious()[IX_S(x, y, m_size)];}
	float getPreDensity(int x, int y)const {return density->getPrevious()[IX_S(x, y, m_size)];}

	void setCurU(int x, int y, float value){u->getCurrent()[IX_S(x, y, m_size)] = value;}
	void setCurV(int x, int y, float value){v->getCurrent()[IX_S(x, y, m_size)] = value;}
	void setCurDensity(int x, int y, float value){density->getCurrent()[IX_S(x, y, m_size)] = value;}

	void setPreU(int x, int y, float value){u->getPrevious()[IX_S(x, y, m_size)] = value;}
	void setPreV(int x, int y, float value){v->getPrevious()[IX_S(x, y, m_size)] = value;}
	void setPreDensity(int x, int y, float value){density->getPrevious()[IX_S(x, y, m_size)] = value;}

	float getTime()const{return m_time;}
	float getViscocity()const{return m_viscocity;}

	static void ExportClass();

private:
	int m_size;
	float m_viscocity;
	float m_time;

	Velocity2D *u;
	Velocity2D *v;
	Velocity2D *density;
};

class EulerGrid3D
{
public:
	EulerGrid3D(int size, float viscocity, float time);
	~EulerGrid3D();

	Velocity3D *getU(){return u;}
	Velocity3D *getV(){return v;}
	Velocity3D *getW(){return w;}
	Velocity3D *getDensity()const{return density;}

	float getCurU(int x, int y, int z)const {return u->getCurrent()[IX3D_S(x, y, z, m_size)];}
	float getCurV(int x, int y, int z)const {return v->getCurrent()[IX3D_S(x, y, z, m_size)];}
	float getCurW(int x, int y, int z)const {return w->getCurrent()[IX3D_S(x, y, z, m_size)];}
	float getCurDensity(int x, int y, int z)const {return density->getCurrent()[IX3D_S(x, y, z, m_size)];}

	float getPreU(int x, int y, int z)const {return u->getPrevious()[IX3D_S(x, y, z, m_size)];}
	float getPreV(int x, int y, int z)const {return v->getPrevious()[IX3D_S(x, y, z, m_size)];}
	float getPreW(int x, int y, int z)const {return w->getPrevious()[IX3D_S(x, y, z, m_size)];}
	float getPreDensity(int x, int y, int z)const {return density->getPrevious()[IX3D_S(x, y, z, m_size)];}

	void setCurU(int x, int y, int z, float value){u->getCurrent()[IX3D_S(x, y, z, m_size)] = value;}
	void setCurV(int x, int y, int z, float value){v->getCurrent()[IX3D_S(x, y, z, m_size)] = value;}
	void setCurW(int x, int y, int z, float value){w->getCurrent()[IX3D_S(x, y, z, m_size)] = value;}
	void setCurDensity(int x, int y, int z, float value){density->getCurrent()[IX3D_S(x, y, z, m_size)] = value;}

	void setPreU(int x, int y, int z, float value){u->getPrevious()[IX3D_S(x, y, z, m_size)] = value;}
	void setPreV(int x, int y, int z, float value){v->getPrevious()[IX3D_S(x, y, z, m_size)] = value;}
	void setPreW(int x, int y, int z, float value){w->getPrevious()[IX3D_S(x, y, z, m_size)] = value;}
	void setPreDensity(int x, int y, int z, float value){density->getPrevious()[IX3D_S(x, y, z, m_size)] = value;}

	float getTime()const{return m_time;}
	float getViscocity()const{return m_viscocity;}

	static void ExportClass();

private:
	int m_size;
	float m_viscocity;
	float m_time;

	Velocity3D *u;
	Velocity3D *v;
	Velocity3D *w;
	Velocity3D *density;
};
#endif
