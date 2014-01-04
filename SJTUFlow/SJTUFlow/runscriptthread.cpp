#include "runscriptthread.h"

#include <QDir>
#include <QSettings>
#include <iostream>

RunScriptThread::RunScriptThread(QObject *parent)
	: QThread(parent)
{
	execStr = tr("import sys\nsys.path.append('%1')\n")
		.arg(QDir::currentPath());
	QSettings settings;
	QStringList sysLibs = settings.value(tr("SysLibs")).toStringList();
	foreach (QString s, sysLibs)
	{
		int pos = s.indexOf('.');
		execStr += tr("import %1\n").arg(s.left(pos));
	}
	QString rstname = tr("%1/%2")
		.arg(settings.value(tr("OutputDir")).toString())
		.arg(settings.value(tr("OutputName")).toString());
	execStr += tr("SJTUFlow_Global.EulerApplication.m_rstname='%1'\n").arg(rstname) 
		+ tr("SJTUFlow_Global.AbstractSPHSolver.m_rstname='%1'\n").arg(rstname);
	pyPath = settings.value(tr("PyPath")).toString();
}

RunScriptThread::~RunScriptThread()
{

}

void RunScriptThread::run()
{
	QProcess* scriptProcess = new QProcess(this);
	connect(scriptProcess, SIGNAL(readyReadStandardError()), 
		this, SLOT(showRunError()));
	connect(scriptProcess, SIGNAL(finished(int, QProcess::ExitStatus)), 
		this, SLOT(processFinished(int, QProcess::ExitStatus)));
	scriptProcess->start(pyPath);
	scriptProcess->waitForStarted();
	scriptProcess->write(execStr.toStdString().c_str());
	scriptProcess->closeWriteChannel();
	scriptProcess->waitForFinished(1000000);
}

void RunScriptThread::setScriptCode( QString code )
{
	execStr += code;
}

void RunScriptThread::showRunError()
{
	QProcess* scriptProcess = qobject_cast<QProcess*>(sender());
	QString errStr = QString::fromLocal8Bit(scriptProcess->readAllStandardError());
	std::cout << errStr.toStdString() << std::endl;
}

void RunScriptThread::processFinished( int, QProcess::ExitStatus )
{

}
