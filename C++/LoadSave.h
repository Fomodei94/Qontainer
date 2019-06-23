#ifndef LOADSAVE_H
#define LOADSAVE_H

#include <QString>
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

void loadFromFile(Qontainer<VideoFile*> *container, QString path){
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray dataByte = file.readAll();
    file.close();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(dataByte);
    QJsonArray jsonArray = jsonDoc.object().value("VideoFile").toArray();

        if(!container->isEmpty()) container->clear();

        foreach(const QJsonValue& value, jsonArray) {


            std::string  title = value.toObject().value("title").toString().toStdString();
            std::string  genre = value.toObject().value("genre").toString().toStdString();
            std::string type = value.toObject().value("type").toString().toStdString();
            std::string  nation = value.toObject().value("nation").toString().toStdString();
            int publishingDate = value.toObject().value("publishingDate").toInt();

            if(type == "Movie"){
                container->pushBack(new Movie(title,genre,nation,publishingDate,
                                                     value.toObject().value("director").toString().toStdString(),
                                                     value.toObject().value("length").toInt()));
            }
            else if(type == "TvSerie"){
                container->pushBack(new TvSerie(title,genre,nation,publishingDate,
                                                   value.toObject().value("seasons").toString().toInt(),
                                                   value.toObject().value("finished").toBool()));
            }
            else if(type == "SportMatch"){
                container->pushBack(new SportMatch(title,genre,nation,publishingDate,
                                                   value.toObject().value("championship").toString().toStdString(),
                                                   value.toObject().value("homeTeam").toString().toStdString(),
                                                   value.toObject().value("guestTeam").toString().toStdString()));
            }

            else if(type == "Anime"){
                container->pushBack(new Anime(title,genre,nation,publishingDate,
                                                   value.toObject().value("episodes").toString().toInt(),
                                                   value.toObject().value("finished").toBool()));
            }
        }
}
#endif // LOADSAVE_H
