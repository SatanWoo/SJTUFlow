//
//  SPHSolver.cpp
//  water_SPH2D
//
//  Created by yangyang on 12/22/13.
//  Copyright (c) 2013 yangyang. All rights reserved.
//

#include "SPHSolver.h"

#include <sstream>
#include <fstream>

#include <QFile>
#include <QDomDocument>

size_t object_count = 0;
Particle objects2D[OBJECT_COUNT];

Particle* grid_object[GRID_SIZE];
size_t neighbour_object[OBJECT_COUNT];
Material object_material = Material(Color(1.0f, 1.0f, 1.0f, 1.0f), 1.0f);


SPHPoly6Solver::SPHPoly6Solver()
{
	for (int i = 0; i < PARTICLE_COUNT; i++)
	{
		particlesArray[i] = &particles[i];
	}
	SetSceneFile();
}

//===========================Init & destroy of Solver===============================
void SPHPoly6Solver::updateObjectGrid()
{
    memset(grid_object, NULL, GRID_SIZE * sizeof(Particle*));
    for (size_t i = 0; i < object_count; i++) {
        Particle& p = objects2D[i];
        
        int x = p.curPos.x * GRID_WIDTH;
        int y = p.curPos.y * GRID_HEIGHT;
        
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
        
        p.next = grid_object[x + y * GRID_WIDTH];
        grid_object[x + y * GRID_WIDTH] = &p;
        p.gridCords.x = x;
        p.gridCords.y = y;
    }
    
    for (size_t i = 0; i < object_count; i++) {
        Particle& pi = objects2D[i];
        size_t gi = pi.gridCords.x;
        size_t gj = pi.gridCords.y * GRID_WIDTH;
        
        pi.neighbour_count = 0;
        
        for (size_t ni = gi - 1; ni <= gi + 1; ni++) {
            for (size_t nj = gj - GRID_WIDTH; nj <= gj + GRID_WIDTH; nj += GRID_WIDTH) {
                for (Particle* ppo = grid_object[ni + nj]; ppo != NULL; ppo = ppo->next) {
                    const Particle& pj = *ppo;
                    
                    float dx = pi.curPos.x - pj.curPos.x;
                    float dy = pi.curPos.y - pj.curPos.y;
                    float r2 = dx * dx + dy * dy;
                    if(r2 < EPSILON2 || r2 > DISTANCE2)
                    {
                        continue;
                    }
                    
                    float r = sqrtf(r2);
                    
                    if (pi.neighbour_count < NEIGHBOURS_MAX_COUNT)
                    {
                        pi.neighbours[pi.neighbour_count] = &pj;
                        pi.distance_neighbours[pi.neighbour_count] = r;
                        pi.neighbour_count++;
                    }
                }
            }
        }
        
        neighbour_object[i] = pi.neighbour_count;
    }
}

void SPHPoly6Solver::SetScene(std::string fileName)
{
    // TODO read the scene file & get the circle and rectangle
	ParseScene(fileName);
//     addRect(Vector2f(0.5, 0.15), 0.1, 0.1);
//     addCir(Vector2f(0.6, 0.14), 0.016);
}

void SPHPoly6Solver::addCir(Vector2f center, float radiuso)
{
    float perimetro = 2 * PI * radiuso;
    for (float i = 0; i < perimetro; i += OBJECT_DISTANCE) {
        
        if(object_count == OBJECT_COUNT)
        {
            return;
        }
        
        Particle& p1 = objects2D[object_count++];
        p1.curPos.x = center.x + radiuso * cosf(i / radiuso);
        p1.curPos.y = center.y + radiuso * sinf(i / radiuso);
        p1.material = object_material;
        p1.isObject = true;
    }
}

void SPHPoly6Solver::addRect(Vector2f p, float width, float height)
{
    for (float i = 0; i <= width;  i += OBJECT_DISTANCE) {
        
        if(object_count == OBJECT_COUNT)
        {
            return;
        }
        Particle& p1 = objects2D[object_count++];
        p1.curPos.x = p.x - width / 2 + i;
        p1.curPos.y = p.y - height / 2;
        p1.material = object_material;
        p1.isObject = true;
        
        if(object_count == OBJECT_COUNT)
        {
            return;
        }
        
        Particle& p2 = objects2D[object_count++];
        p2.curPos.x = p.x - width / 2 + i;
        p2.curPos.y = p.y + height / 2;
        p2.material = object_material;
        p2.isObject = true;
    }
    
    for (float i = 0; i <= height; i += OBJECT_DISTANCE) {
        if(object_count == OBJECT_COUNT)
        {
            return;
        }
        Particle& p1 = objects2D[object_count++];
        p1.curPos.x = p.x - width / 2;
        p1.curPos.y = p.y - height / 2 + i;
        p1.material = object_material;
        p1.isObject = true;
        
        if(object_count == OBJECT_COUNT)
        {
            return;
        }
        
        Particle& p2 = objects2D[object_count++];
        p2.curPos.x = p.x + width / 2;
        p2.curPos.y = p.y - height / 2 + i;
        p2.material = object_material;
        p2.isObject = true;
    }
}

void SPHPoly6Solver::SolverInitSPH(float density, int particleNum)
{
    this->density = density;
    this->totalParticleNum = particleNum;
	curParticleNum = 0;
}

//===========================Main loop of simulations==========================
void SPHPoly6Solver::Emit(void)
{
    curParticleNum = emitStrategy->EmitParticles(curParticleNum, density, particlesArray);
}

void SPHPoly6Solver::BodyForce(void)
{
    bodyForceStrategy->ApplyBodyForce(curParticleNum, density, particlesArray);
}

void SPHPoly6Solver::UpdateGrid(void)
{
    updateGridStrategy->UpdateGrid(curParticleNum, particlesArray);
}

void SPHPoly6Solver::CalPressure(void)
{
    calPressureStrategy->CalPressure(curParticleNum, particlesArray);
}

void SPHPoly6Solver::RelaxPos(void)
{
    relaxPosStrategy->RelaxPos(curParticleNum, density, particlesArray);
}

void SPHPoly6Solver::Collision(void)
{
    collisionStrategy->Collision(curParticleNum, density, particlesArray, sv.m_scname);
}

void SPHPoly6Solver::RenderInit(void)
{
    renderSPHStrategy->RenderInit();
}

void SPHPoly6Solver::ExportClass()
{
	class_<SPHPoly6Solver, bases<AbstractSPHSolver> >("SPHPoly6Solver", init<>())
		.def("SetScene", &SPHPoly6Solver::SetScene)
		.def("SolverInitSPH", &SPHPoly6Solver::SolverInitSPH)
		.def("Emit", &SPHPoly6Solver::Emit)
		.def("BodyForce", &SPHPoly6Solver::BodyForce)
		.def("UpdateGrid", &SPHPoly6Solver::UpdateGrid)
		.def("CalPressure", &SPHPoly6Solver::CalPressure)
		.def("RelaxPos", &SPHPoly6Solver::RelaxPos)
		.def("Collision", &SPHPoly6Solver::Collision)
		.def("RenderInit", &SPHPoly6Solver::RenderInit)
		.def_readwrite("sv", &SPHPoly6Solver::sv);
}

void SPHPoly6Solver::Display()
{
	renderSPHStrategy->RenderSPH(curParticleNum, particlesArray, sv.m_scname);
}

void SPHPoly6Solver::SaveResults( std::string rstname, int i )
{
	using namespace std;
	stringstream ss;
	ss << i;
	string num;
	ss >> num;
	string realName = rstname + "_" + num + ".txt";

	ofstream out(realName);
	if (!out)
	{
		return;
	}

	out << "#particle num\n#pos_x pos_y\n#...\n";
	out << curParticleNum << endl;
	for (int i = 0; i < curParticleNum; i++)
	{
		out << particles[i].curPos.x << " "
			<< particles[i].curPos.y << "\n";
	}

	out.close();
}

void SPHPoly6Solver::ParseScene(std::string fileName)
{
	object_count = 0;
	if (fileName == "")
	{
		return;
	}
	QFile file(fileName.c_str());
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		return;
	}

	QDomDocument doc;
	QString errStr;
	int errLine, errCol;
	if (!doc.setContent(&file, false, &errStr, &errLine, &errCol))
	{
		return;
	}
	QDomElement root = doc.documentElement();
	QDomElement node = root.firstChildElement(QString("Scene"));
	if (node.isNull())
	{
		return;
	}
	int mode = node.attribute(QString("mode"), QString("-1")).toInt();
	if (mode != 0)
	{
		return;
	}
	std::cout << "ssss" << std::endl;
	QDomNodeList children = node.childNodes();
	for (int i = 0; i < children.count(); i++)
	{
		QDomElement child = children.at(i).toElement();
		if (child.tagName() == QString("Primitive"))
		{
			int t = child.attribute(QString("type"), QString("-1")).toInt();
			if (t == 0) // rectangle
			{
				QDomElement e = child.firstChildElement(QString("frame"));
				e = e.firstChildElement(QString("position"));
				float x = e.attribute(QString("x"), QString("0")).toFloat();
				float y = e.attribute(QString("y"), QString("0")).toFloat();
				e = child.firstChildElement(QString("size"));
				float w = e.attribute(QString("x"), QString("0.2")).toFloat();
				float h = e.attribute(QString("y"), QString("0.2")).toFloat();
				addRect(Vector2f(x, y), w, h);
			}
			else if (t == 1) // circle
			{
				float radius = child.attribute(QString("radius"), QString("0.1")).toFloat();
				QDomElement e = child.firstChildElement(QString("frame"));
				e = e.firstChildElement(QString("position"));
				float x = e.attribute(QString("x"), QString("0")).toFloat();
				float y = e.attribute(QString("y"), QString("0")).toFloat();
				addCir(Vector2f(x, y), radius);
			}
		}
	}
	updateObjectGrid();
}
