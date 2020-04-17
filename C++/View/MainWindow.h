#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGridLayout>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollArea>
#include <QPushButton>
#include <QString>
#include "../Model/Qontainer.h"
#include "../Model/VideoFile.h"
#include "../LoadSave.h"
#include "setObjectWidget.h"
#include "searchByWidget.h"
#include "modifyWidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
	Qontainer<VideoFile*> *container;
  Qontainer<VideoFile*> *findResult;
	QGridLayout* winLayout;
	QWidget* centralWidget;
  QLabel *listTitle,
          *dynamicSearchLabel;
  QLineEdit *dynamicSearchBox;
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
  //void searchComplete();

private slots:
	void windowSelector();
	void openInsertWindow();
  void openModifyWindow(QListWidgetItem*);
  void showListFromContainer();
  void showFromFile();
  void showFindResults(Qontainer<VideoFile*> *results);
  void saveContainerToFile();
};

#endif // MAINWINDOW_H
