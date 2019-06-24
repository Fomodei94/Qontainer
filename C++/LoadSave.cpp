#include "LoadSave.h"

void loadFromFile(Qontainer<VideoFile*> *container, QString path){
    QFile file(path);
    if(!file.exists()) {
      QMessageBox msgBox;
      msgBox.setWindowTitle("Warning");
  		msgBox.setText("There was an error opening savedLibrary.json, check if the file exists!");
  		msgBox.exec();
    }
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
                                                   value.toObject().value("seasons").toInt(),
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
                                                   value.toObject().value("episodes").toInt(),
                                                   value.toObject().value("finished").toBool()));
            }
        }
}

void saveToFile(Qontainer<VideoFile*> *container, QString path) {

      QJsonArray jsonArray;

      for(unsigned int i = 0; i<container->getObjCount(); i++){
          if(dynamic_cast<Movie*>((*container)[i])) {
              Movie* aux = dynamic_cast<Movie*>((*container)[i]);
              auto toSave = QJsonObject(
              {
                  qMakePair(QString("title"), QJsonValue(QString::fromStdString(aux->getTitle()))),
                  qMakePair(QString("genre"), QJsonValue(QString::fromStdString(aux->getGenre()))),
                  qMakePair(QString("publishingDate"), QJsonValue(aux->getPublishingYear())),
                  qMakePair(QString("nation"), QJsonValue(QString::fromStdString(aux->getNation()))),
                  qMakePair(QString("type"), QJsonValue(QString("Movie"))),
                  qMakePair(QString("director"), QJsonValue(QString::fromStdString(aux->getDirector()))),
                  qMakePair(QString("length"), QJsonValue(aux->getLength()))
              });
              jsonArray.push_back(QJsonValue(toSave));

          }
          else if(dynamic_cast<TvSerie*>((*container)[i])) {
              TvSerie* aux = dynamic_cast<TvSerie*>((*container)[i]);
              auto toSave = QJsonObject(
              {
                  qMakePair(QString("title"), QJsonValue(QString::fromStdString(aux->getTitle()))),
                  qMakePair(QString("genre"), QJsonValue(QString::fromStdString(aux->getGenre()))),
                  qMakePair(QString("publishingDate"), QJsonValue(aux->getPublishingYear())),
                  qMakePair(QString("nation"), QJsonValue(QString::fromStdString(aux->getNation()))),
                  qMakePair(QString("type"), QJsonValue(QString("TvSerie"))),
                  qMakePair(QString("seasons"), QJsonValue(aux->getSeasons())),
                  qMakePair(QString("finished"), QJsonValue(aux->isFinished()))
              });
              jsonArray.push_back(QJsonValue(toSave));


          }
          else if(dynamic_cast<Anime*>((*container)[i])) {
              Anime* aux = dynamic_cast<Anime*>((*container)[i]);
              auto toSave = QJsonObject(
              {
                  qMakePair(QString("title"), QJsonValue(QString::fromStdString(aux->getTitle()))),
                  qMakePair(QString("genre"), QJsonValue(QString::fromStdString(aux->getGenre()))),
                  qMakePair(QString("publishingDate"), QJsonValue(aux->getPublishingYear())),
                  qMakePair(QString("nation"), QJsonValue(QString::fromStdString(aux->getNation()))),
                  qMakePair(QString("type"), QJsonValue(QString("Anime"))),
                  qMakePair(QString("episodes"), QJsonValue(aux->getEpisodes())),
                  qMakePair(QString("finished"), QJsonValue(aux->isFinished()))
              });
              jsonArray.push_back(QJsonValue(toSave));


          }
          else if(dynamic_cast<SportMatch*>((*container)[i])) {
              SportMatch* aux = dynamic_cast<SportMatch*>((*container)[i]);
              auto toSave = QJsonObject(
              {
                  qMakePair(QString("title"), QJsonValue(QString::fromStdString(aux->getTitle()))),
                  qMakePair(QString("genre"), QJsonValue(QString::fromStdString(aux->getGenre()))),
                  qMakePair(QString("publishingDate"), QJsonValue(aux->getPublishingYear())),
                  qMakePair(QString("nation"), QJsonValue(QString::fromStdString(aux->getNation()))),
                  qMakePair(QString("type"), QJsonValue(QString("SportMatch"))),
                  qMakePair(QString("championship"), QJsonValue(QString::fromStdString(aux->getChampionship()))),
                  qMakePair(QString("homeTeam"), QJsonValue(QString::fromStdString(aux->getHomeTeam()))),
                  qMakePair(QString("guestTeam"), QJsonValue(QString::fromStdString(aux->getGuestTeam())))
              });
              jsonArray.push_back(QJsonValue(toSave));


          }

          else {
              VideoFile* aux = (*container)[i];
              auto toSave = QJsonObject(
              {
                  qMakePair(QString("title"), QJsonValue(QString::fromStdString(aux->getTitle()))),
                  qMakePair(QString("genre"), QJsonValue(QString::fromStdString(aux->getGenre()))),
                  qMakePair(QString("publishingDate"), QJsonValue(aux->getPublishingYear())),
                  qMakePair(QString("nation"), QJsonValue(QString::fromStdString(aux->getNation()))),
                  qMakePair(QString("type"), QJsonValue(QString("VideoFile")))
              });
              jsonArray.push_back(QJsonValue(toSave));
          }

      }

      QJsonObject toSaveFinal;
      toSaveFinal.insert(QString("VideoFile"), QJsonValue(jsonArray));
      QJsonDocument jsonDoc(toSaveFinal);
      QString toWrite = jsonDoc.toJson();
      QFile saveFile(path);
      saveFile.open(QIODevice::WriteOnly);
      saveFile.write(toWrite.toLocal8Bit());
      saveFile.close();
}
