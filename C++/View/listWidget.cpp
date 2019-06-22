#include "listWidget.h"

listWidget::listWidget(Qontainer<deeptr<VideoFile>> *VideoContainer, QWidget *parent) : VideoContainer(VideoContainer) {

  list = new QListWidget(this);


  scroll = new QScrollArea;
  scroll->setWidget(list);
}
