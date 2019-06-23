#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QListWidget>
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

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
	Qontainer<VideoFile*> *container;
	QGridLayout* winLayout;
	QWidget* centralWidget;
	QListWidget *objectList;
  QScrollArea *scrollArea;
	QPushButton	*insertButton,
				*removeButton,
				*findButton,
				*saveButton;
	setObjectWidget *objectWindow;
	searchByWidget	*searchWindow;

public:
    MainWindow(Qontainer<VideoFile*> *container, QWidget *parent = 0);
    ~MainWindow();

	void openSelectWindow(bool remove);

/*
private slots:
    bool fillFromFile(QString);
    bool saveToFile(Cvector<deeptr<ship> >, QString)const;
    void buildListBy(QString = "",QString = "",QString = "");
*/
public slots:
	void windowSelector();
	void openInsertWindow();

};

#endif // MAINWINDOW_H
