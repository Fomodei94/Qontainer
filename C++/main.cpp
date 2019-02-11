#include "View/MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qontainer<VideoFile> *container;
    MainWindow w(container);
    w.show();

    return a.exec();
}
