#include "renderthread.h"



void RenderThread::run()
{
	Renderer::RenderEuler3D(sp.density, sp.size, 
		sp.frameCnt, filename.toStdString().c_str(), width, height);
}

void RenderThread::setData( SocketPackageEuler* sp_, 
	QString filename_, int width_, int height_ )
{
	sp.frameCnt = sp_->frameCnt;
	sp.size = sp_->size;
	sp.totalSize = sp_->totalSize;
	sp.density = new float[sp.totalSize];
	memcpy(sp.density, sp_->density, sp.totalSize * sizeof(float));
	filename = filename_;
	width = width_;
	height = height_;
}
