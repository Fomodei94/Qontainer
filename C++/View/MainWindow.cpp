#include "MainWindow.h"

MainWindow::MainWindow(Qontainer<VideoFile*> *container, QWidget *parent) : QMainWindow(parent), container(container) {
	// Set MainWindow properties
	setWindowTitle("Qontainer");
	setMinimumSize(800,500);

	//container = new Qontainer<VideoFile>();

	centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);
	winLayout = new QGridLayout(centralWidget);

	listTitle = new QLabel("<h1>My media library:    </h1>",centralWidget);
	objectList = new QListWidget(centralWidget);
	scrollArea = new QScrollArea;
	scrollArea->setWidget(objectList);
	insertButton = new QPushButton("Insert Item", centralWidget);
	removeButton = new QPushButton("Remove Items", centralWidget );
	findButton = new QPushButton("Find Items", centralWidget);
	saveButton = new QPushButton("Save to file", centralWidget);
	loadButton = new QPushButton("Load from file", centralWidget);

	refreshButton = new QPushButton("Refresh list", centralWidget);

	// Layout setting
	winLayout->addWidget(listTitle,0,1,1,3);
	winLayout->addWidget(objectList,1,0,3,3);
	winLayout->addWidget(insertButton,4,0);
	winLayout->addWidget(removeButton,4,1);
	winLayout->addWidget(findButton,4,2);
	winLayout->addWidget(refreshButton,1,3,2,1);
	winLayout->addWidget(saveButton,2,3,2,1);
	winLayout->addWidget(loadButton,3,3,2,1);

	setLayout(winLayout);

	showListFromContainer();

	// Connect Signals:
	connect(insertButton, SIGNAL(clicked()), this, SLOT(openInsertWindow()));
	connect(removeButton, SIGNAL(clicked()), this, SLOT(windowSelector()));
	connect(findButton, SIGNAL(clicked()), this, SLOT(windowSelector()));
	connect(refreshButton, SIGNAL(clicked()), this, SLOT(showListFromContainer()));
	connect(this, SIGNAL(listUpdated()), this, SLOT(showListFromContainer()));
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

void MainWindow::showListFromContainer() {
	objectList->clear();
	for(int i=0; i < container->getObjCount(); i++)
	  objectList->addItem(new QListWidgetItem(QString::fromStdString((*container)[i]->getTitle())));
}

MainWindow::~MainWindow() {

}
