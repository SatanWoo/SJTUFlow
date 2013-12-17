#include "scenecommand.h"

#include "objloader.h"

SceneCommand::SceneCommand(Scene *scene_, QUndoCommand *parent)
	: QUndoCommand(parent), scene(scene_)
{
}

SceneNewCommand::SceneNewCommand( Primitive::Type type_, 
	Scene *scene_, QUndoCommand *parent )
	: SceneCommand(scene_, parent)
{
	switch (type_)
	{
	case Primitive::T_Circle:
		p = new Circle;
		break;
	case Primitive::T_Rect:
		p = new SceneUnit::Rectangle;
		break;
	case Primitive::T_Sphere:
		p = new Sphere(Scene::getQuadric());
		break;
	case Primitive::T_Box:
		p = new Box;
		break;
	case Primitive::T_Object:
		p = new Object;
		break;
	default:
		p = NULL;
		break;
	}
	Q_ASSERT(p != NULL);
	p->setColor(RAND_COLOR);
	p->setName(scene->defaultName(type_));
	p->setId(scene->getAnID());
}

void SceneNewCommand::undo()
{
	scene->deletePrimitive(p->getId());
	scene->decreaseID();
	scene->decreaseNum(p->getType());
}

void SceneNewCommand::redo()
{
	scene->appendPrimitive(p);
	scene->increaseID();
	scene->increaseNum(p->getType());
}

SceneImportCommand::SceneImportCommand( Scene *scene_, QUndoCommand *parent )
    : SceneNewCommand(Primitive::T_Object, scene_, parent)
{
}

bool SceneImportCommand::import( QString filename )
{
	Object *o = (Object *)p;
	if (ObjLoader::load(filename, o))
	{
		o->adjust();
		return true;
	}
	return false;
}

SceneDeleteCommand::SceneDeleteCommand( int id_, Scene *scene_, QUndoCommand *parent )
	: SceneCommand(scene_, parent)
{
	p = scene->getPrimitive(id_);
	Q_ASSERT(p != NULL);
}

void SceneDeleteCommand::undo()
{
	scene->appendPrimitive(p);
}

void SceneDeleteCommand::redo()
{
	scene->deletePrimitive(p->getId());
}

PrimitiveOperateCommand::PrimitiveOperateCommand( Primitive *p_, QUndoCommand *parent )
	: QUndoCommand(parent), p(p_)
{
	oldPos = p->getCenter();
	oldOri = p->orientation();
	oldScalar = p->getScalar();
}

void PrimitiveOperateCommand::setNewData()
{
	newPos = p->getCenter();
	newOri = p->orientation();
	newScalar = p->getScalar();
}

void PrimitiveOperateCommand::undo()
{
	p->setCenter(oldPos);
	p->setOrientation(oldOri);
	p->setScalar(oldScalar);
}

void PrimitiveOperateCommand::redo()
{
	p->setCenter(newPos);
	p->setOrientation(newOri);
	p->setScalar(newScalar);
}
