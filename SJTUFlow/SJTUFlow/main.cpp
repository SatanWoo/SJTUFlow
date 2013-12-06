#include "sjtuflow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	glutInit(&argc, argv);
	SJTUFlow w;
	w.show();
	return a.exec();
}
