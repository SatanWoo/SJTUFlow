#include "displaywidget.h"

#include <QLocalSocket>
#include <QDataStream>
#include <QDebug>

DisplayWidget::DisplayWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	localServer = new QLocalServer(this);
	if (!localServer->listen(QApplication::applicationName()))
	{
		qDebug() << "failed to listen" << QApplication::applicationName() << endl;
	}
	connect(localServer, SIGNAL(newConnection()), this, SLOT(dealConnection()));

	scene = new Scene;
	setCentralWidget(scene);

	//example
// 	scene->clear(Scene::SCENE_3D);
// 	scene->newPrimitive(SceneUnit::Primitive::T_Sphere);
    //SceneUnit::Primitive *p = scene->getPrimitive(0);
	//scene->setAnimate();
	scene->setAllowSelect();

	scene->startAnimation();
}

DisplayWidget::~DisplayWidget()
{
	localServer->close();
	QLocalServer::removeServer(QApplication::applicationName());
}

void DisplayWidget::cloneScene( Scene *scene_ )
{
	scene->clone(scene_);
}

void DisplayWidget::dealConnection()
{
	QLocalSocket *socket = localServer->nextPendingConnection();
// 	connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));
// 	connect(socket, SIGNAL(disconnected()), socket, SLOT(abort()));
	socket->waitForReadyRead();
	QDataStream ds(socket);

	SocketPackage sp;
	ds.readRawData((char *)(&sp), sizeof(SocketPackage));
	scene->setSocketPackage(sp);

	socket->disconnectFromServer();
}

void DisplayWidget::readData()
{
	QLocalSocket *socket = qobject_cast<QLocalSocket *>(sender());
}
