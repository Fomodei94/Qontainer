#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QVBoxLayout>
#include "../Model/Qontainer.h"
#include "../Model/VideoFile.h"
#include "../Model/Movie.h"
#include "../Model/Anime.h"
#include "../Model/TvSerie.h"
#include "../Model/SportMatch.h"


class tableWidget : public QTableWidget{
private:
    Q_OBJECT
    Qontainer<VideoFile*> * itemList;

public:
    tableWidget(Qontainer<VideoFile*> *itemList, QWidget *parent=0);
    
    /*
    void viewUsers();
    void addListUsers(User*);
    void addListUsers(QList<User*>);
    void addListAllUsers();
    void addItemUser(int, User*);

    void viewItems();
    void addListItems(Item*);
    void addListItems(QList<Item*>);
    void addListAllItems();
    void addItemItem(int, Item*);

signals:
    void clicked(int,int); */
};
#endif //TABLEWIDGET_H
