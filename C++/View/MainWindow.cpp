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
	removeButton = new QPushButton("Remove Item(s)", centralWidget );
	findButton = new QPushButton("Find", centralWidget);
	saveButton = new QPushButton("Save Changes", centralWidget);

	// Layout setting
	winLayout->addWidget(table,0,0,1,5);
	winLayout->addWidget(insertButton,1,0);
	winLayout->addWidget(removeButton,1,1);
	winLayout->addWidget(findButton,1,2);
	winLayout->addWidget(saveButton,1,4);
	setLayout(winLayout);

	// Connect Signals:
	connect(insertButton, SIGNAL(clicked()), this, SLOT(windowSelector()));
	connect(removeButton, SIGNAL(clicked()), this, SLOT(windowSelector()));
	connect(findButton, SIGNAL(clicked()), this, SLOT(windowSelector()));
}

void MainWindow::windowSelector() {
	if (QPushButton* button = dynamic_cast<QPushButton*>(sender())) {
		if (button == insertButton) openSelectWindow("Insert");
		else if(button == removeButton) openSelectWindow("Remove");
		else if(button == findButton) openSelectWindow("Find");
		}
	else throw("Bad Signal/Slot combo");
}

void MainWindow::openSelectWindow(const QString& func) {
	objectWindow = new setObjectWidget(container, func);
	(*objectWindow).show();
}

MainWindow::~MainWindow() {

}
