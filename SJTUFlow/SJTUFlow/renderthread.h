#ifndef RENDERTHREAD_H
#define RENDERTHREAD_H

#include <QThread>
#include <QRunnable>
#include <QThreadPool>

#include "renderer.h"

#include "../SJTUFlow_Global/global.h"

class RenderThread : public QRunnable
{
public:
// 	RenderThread(QObject *parent = 0);
// 	~RenderThread();

	void run();

	void setData(SocketPackageEuler* sp_, 
		QString filename_, int width_, int height_);

private:
	SocketPackageEuler sp;
	QString filename;
	int width;
	int height;

};

#endif // RENDERTHREAD_H
