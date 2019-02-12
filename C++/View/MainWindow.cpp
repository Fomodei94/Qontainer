#include "MainWindow.h"

MainWindow::MainWindow(Qontainer<VideoFile> *container, QWidget *parent) : QMainWindow(parent), container(container) {
	// Set MainWindow properties
	setWindowTitle("Qontainer");
	setMinimumSize(800,500);

	//container = new Qontainer<VideoFile>();

	centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);
	winLayout = new QGridLayout(centralWidget);

	table = new QTableView(centralWidget);
	insertButton = new QPushButton("Insert Item", centralWidget);
	removeButton = new QPushButton("Remove Items", centralWidget );
	findButton = new QPushButton("Find Items", centralWidget);
	saveButton = new QPushButton("Save Changes", centralWidget);

	// Layout setting
	winLayout->addWidget(table,0,0,1,5);
	winLayout->addWidget(insertButton,1,0);
	winLayout->addWidget(removeButton,1,1);
	winLayout->addWidget(findButton,1,2);
	winLayout->addWidget(saveButton,1,4);
	setLayout(winLayout);

	// Connect Signals:
	connect(insertButton, SIGNAL(clicked()), this, SLOT(openInsertWindow()));
	connect(removeButton, SIGNAL(clicked()), this, SLOT(windowSelector()));
	connect(findButton, SIGNAL(clicked()), this, SLOT(windowSelector()));
}

void MainWindow::openInsertWindow() {
	objectWindow = new setObjectWidget(container);
	(*objectWindow).show();
}

void MainWindow::windowSelector() {
	if (QPushButton* button = dynamic_cast<QPushButton*>(sender())) {
		if(button == removeButton) openSelectWindow(true);
		else if(button == findButton) openSelectWindow(false);
		}
	else throw("Bad Signal/Slot combo");
}

void MainWindow::openSelectWindow(bool remove) {
	searchWindow = new searchByWidget(container, remove);
	(*searchWindow).show();
}

MainWindow::~MainWindow() {

}
