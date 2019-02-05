#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include "SelectItemWindow.h"

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
	SelectItemWindow *selectItemWindow;	

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
	void openSelectWindow();
};

#endif // MAINWINDOW_H
