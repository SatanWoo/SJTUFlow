#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include "scene.h"

#include <QUndoCommand>
#include <QDomElement>

#include <qglviewer.h>

using namespace SceneUnit;

class SceneCommand : public QUndoCommand
{
public:
	SceneCommand(){};
	SceneCommand(Scene *scene_, QUndoCommand *parent = 0);
	~SceneCommand(){}

	virtual void undo() = 0;
	virtual void redo() = 0;

protected:
	Scene *scene;
};

class SceneNewCommand : public SceneCommand
{
public:
	SceneNewCommand(Primitive::Type type_, Scene *scene_, QUndoCommand *parent = 0);
	~SceneNewCommand(){ if (p != NULL) delete p; }

	void undo();
	void redo();

protected:
	Primitive *p;
};

class SceneImportCommand : public SceneNewCommand
{
public:
	SceneImportCommand(Scene *scene_, QUndoCommand *parent = 0);

	bool import(QString filename);
};

class SceneDeleteCommand : public SceneCommand
{
public:
	SceneDeleteCommand(int id_, Scene *scene_, QUndoCommand *parent = 0);

	void undo();
	void redo();

protected:
	Primitive *p;
};

class PrimitiveOperateCommand : public QUndoCommand
{
public:
	PrimitiveOperateCommand(Primitive *p_, QUndoCommand *parent = 0);

	void setNewData();

	void undo();
	void redo();

private:
	Primitive *p;
	qglviewer::Vec oldPos, newPos;
	qglviewer::Quaternion oldOri, newOri;
	double oldScalar, newScalar;
};

#endif // SCENECOMMAND_H
