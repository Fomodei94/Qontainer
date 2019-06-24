#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollArea>
#include <QPushButton>
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
#include "../Model/Qontainer.h"
#include "../Model/VideoFile.h"
#include "setObjectWidget.h"
#include "searchByWidget.h"
#include "modifyWidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
	Qontainer<VideoFile*> *container;
	QGridLayout* winLayout;
	QWidget* centralWidget;
  QLabel *listTitle;
	QListWidget *objectList;
  QScrollArea *scrollArea;
	QPushButton	*insertButton,
				*removeButton,
				*findButton,
        *refreshButton,
        *loadButton,
				*saveButton;
	setObjectWidget *objectWindow;
	searchByWidget	*searchWindow;
  modifyWidget  *modifyWindow;

public:
    MainWindow(Qontainer<VideoFile*> *container, QWidget *parent = 0);
    ~MainWindow();

	void openSelectWindow(bool remove);

/*
private slots:
    bool fillFromFile(QString);
    bool saveToFile(Cvector<deeptr<ship> >, QString)const;
*/

signals:
  void listUpdated();

public slots:
	void windowSelector();
	void openInsertWindow();
  void openModifyWindow(QListWidgetItem* item);
  void showListFromContainer();

};

#endif // MAINWINDOW_H
