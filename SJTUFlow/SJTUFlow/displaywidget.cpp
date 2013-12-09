#include "displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	scene = new Scene;

	setCentralWidget(scene);

	//example
	scene->clear(Scene::SCENE_3D);
	scene->newPrimitive(SceneUnit::Primitive::T_Sphere);
    //SceneUnit::Primitive *p = scene->getPrimitive(0);
	scene->setAnimate();

	scene->startAnimation();
}

DisplayWidget::~DisplayWidget()
{

}
