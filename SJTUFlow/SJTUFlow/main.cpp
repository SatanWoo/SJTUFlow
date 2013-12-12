#include "sjtuflow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setOrganizationName("SJTU DALAB");
	a.setApplicationName("SJTU Flow");
	a.setApplicationVersion("0.6");
	glutInit(&argc, argv);
	SJTUFlow w;
	w.show();
	return a.exec();
}
