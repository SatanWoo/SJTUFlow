#include "displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	scene = new Scene;

	setCentralWidget(scene);

	//example
	scene->clear(Scene::SCENE_3D);
	scene->newSphere();
	SceneUnit::Primitive *p = scene->getPrimitive(0);
	GLdouble center[3] = {0.0, 0.0, 0.0};
	p->setCenter(center);
	scene->setAnimate();

	scene->startAnimation();
}

DisplayWidget::~DisplayWidget()
{

}
