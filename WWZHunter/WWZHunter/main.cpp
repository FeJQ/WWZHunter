#include "WWZHunter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WWZHunter w;
	w.show();
	return a.exec();
}
