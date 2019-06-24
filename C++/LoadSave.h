#ifndef LOADSAVE_H
#define LOADSAVE_H

#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QScrollArea>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QTextStream>
#include "Model/Qontainer.h"

void loadFromFile(Qontainer<VideoFile*> *container, QString path);

void saveToFile(Qontainer<VideoFile*> *container, QString path);

#endif // LOADSAVE_H
