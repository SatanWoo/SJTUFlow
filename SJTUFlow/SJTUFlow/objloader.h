#ifndef OBJLOADER_H
#define OBJLOADER_H

#include "primitive.h"

using namespace SceneUnit;

class ObjLoader
{
public:
	ObjLoader();
	~ObjLoader();

	static bool load(const QString filename, Object *object);
};

#endif