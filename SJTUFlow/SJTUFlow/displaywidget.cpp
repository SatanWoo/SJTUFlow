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

void DisplayWidget::startAnimate()
{
	scene->startAnimation();
}

void DisplayWidget::stopAnimate()
{
	scene->stopAnimation();
}

void DisplayWidget::dealConnection()
{
	QLocalSocket *socket = localServer->nextPendingConnection();
	socket->waitForReadyRead();
	QDataStream ds(socket);

	SocketPackage sp;
	ds.readRawData((char *)(&sp), sizeof(SocketPackage));
	scene->setSocketPackage(sp);

	socket->disconnectFromServer();
}
