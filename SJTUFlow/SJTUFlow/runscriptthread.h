#ifndef RUNSCRIPTTHREAD_H
#define RUNSCRIPTTHREAD_H

#include <QThread>
#include <QProcess>

class RunScriptThread : public QThread
{
	Q_OBJECT

public:
	RunScriptThread(QObject *parent = 0);
	~RunScriptThread();

	virtual void run();
	void setScriptCode(QString code);

private:
	QString execStr;
	QString pyPath;

private slots:
	void showRunError();
	void processFinished(int, QProcess::ExitStatus);
};

#endif // RUNSCRIPTTHREAD_H
