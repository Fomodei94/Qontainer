#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	// Set MainWindow properties
	setWindowTitle("Qontainer");
	setMinimumSize(800,500);
	
	centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);
	winLayout = new QGridLayout(centralWidget);
	
	table = new QTableView(centralWidget);
	insertButton = new QPushButton("Insert Item", centralWidget);
	removeButton = new QPushButton("Remove Item(s)", centralWidget );
	findButton = new QPushButton("Find", centralWidget);
	saveButton = new QPushButton("Save Changes", centralWidget);
	loadButton = new QPushButton("Reload from file", centralWidget);
	
	// Layout setting
	winLayout->addWidget(table,0,0,1,6);
	winLayout->addWidget(insertButton,1,0);
	winLayout->addWidget(removeButton,1,1);
	winLayout->addWidget(findButton,1,2);
	winLayout->addWidget(saveButton,1,4);
	winLayout->addWidget(loadButton,1,5);
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
	objectWindow = new setObjectWidget(func);
	(*objectWindow).show();
}

MainWindow::~MainWindow() {
	
}
