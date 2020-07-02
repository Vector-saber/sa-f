#include "buttonwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    buttonWindow w;
    w.setWindowTitle(QObject::tr("计算器"));
    w.show();

    return a.exec();
}
