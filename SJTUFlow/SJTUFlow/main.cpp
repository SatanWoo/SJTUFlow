#include "sjtuflow.h"
#include <QtWidgets/QApplication>

#ifdef Q_OS_MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setOrganizationName("SJTU DALAB");
	a.setApplicationName("SJTU Flow");
	a.setApplicationVersion("0.6");

#ifndef Q_OS_MAC
	glutInit(&argc, argv);
#endif

	SJTUFlow w;
	w.show();
    w.move(100, 25);
	return a.exec();
}
