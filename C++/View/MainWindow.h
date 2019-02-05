#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include "addItemWindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
	QGridLayout* winLayout;
	QWidget* centralWidget;
	QTableView* table;
	QPushButton	*insertButton,
				*removeButton,
				*searchButton,
				*saveButton,
				*loadButton;
	
	

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
