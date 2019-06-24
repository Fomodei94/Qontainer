#include "View/MainWindow.h"
#include <QApplication>
#include "LoadSave.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qontainer<VideoFile*> *container = new Qontainer<VideoFile*>();
    loadFromFile(container, QString("./savedLibrary.json"));
    MainWindow w(container);
    w.show();

    return a.exec();
}
