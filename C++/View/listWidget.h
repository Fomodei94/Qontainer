#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QScrollArea>
#include "../Model/Qontainer.h"

class listWidget : public QWidget {
  Q_OBJECT

  private:
    Qontainer<VideoFile*> *VideoContainer;
    QListWidget *list;
    QScrollArea *scroll;

  public:
    listWidget(Qontainer<VideoFile*> *VideoContainer, QWidget *parent =0);

};

#endif // LISTWIDGET_H
