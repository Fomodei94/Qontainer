#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QString>
#include "../Model/Qontainer.h"
#include "../Model/VideoFile.h"
#include "setObjectWidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
	Qontainer<VideoFile>* container;
	QGridLayout* winLayout;
	QWidget* centralWidget;
	QTableView* table;
	QPushButton	*insertButton,
				*removeButton,
				*findButton,
				*saveButton,
				*loadButton;
	setObjectWidget *objectWindow;	

public:
    MainWindow(Qontainer<VideoFile> *container, QWidget *parent = 0);
    ~MainWindow();
    
public slots:
	void windowSelector();
	void openSelectWindow(const QString& func);
	
};

#endif // MAINWINDOW_H
