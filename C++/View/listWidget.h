#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QScrollArea>
#include "../Model/Qontainer.h"
#include "../Model/DeepPtr.h"

class listWidget : public QWidget {
  Q_OBJECT

  private:
    Qontainer<deeptr<VideoFile>> *VideoContainer;
    QListWidget *list;
    QScrollArea *scroll;

  public:
    listWidget(Qontainer<deeptr<VideoFile>> *VideoContainer, QWidget *parent =0);

};

#endif // LISTWIDGET_H
