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
	searchButton = new QPushButton("Search", centralWidget);
	saveButton = new QPushButton("Save Changes", centralWidget);
	loadButton = new QPushButton("Reload from file", centralWidget);
	
	// Layout setting
	winLayout->addWidget(table,0,0,1,6);
	winLayout->addWidget(insertButton,1,0);
	winLayout->addWidget(removeButton,1,1);
	winLayout->addWidget(searchButton,1,2);
	winLayout->addWidget(saveButton,1,4);
	winLayout->addWidget(loadButton,1,5);
	setLayout(winLayout);
	
	// Connect Signals:
	connect(insertButton, SIGNAL(clicked()), this, SLOT(openSelectWindow()));
}

void MainWindow::openSelectWindow() {
	selectItemWindow = new SelectItemWindow();
	(*selectItemWindow).show();
}

MainWindow::~MainWindow() {
	
}
