#include "MainWindow.h"

MainWindow::MainWindow(Qontainer<VideoFile*> *container, QWidget *parent) : QMainWindow(parent), container(container) {
	// Set MainWindow properties
	setWindowTitle("Qontainer");
	setFixedSize(800,500);

	// Styling parameters
	const QString windowStyle = "background-color:#3a3a3a; color:#FFFFFF;";
	const QString buttonStyle = "background-color:#2a2a2a; margin: 0px 15px 25px 15px; color:#FFFFFF;border: 0.5px solid #AAAAAA; padding: 1px;";

	centralWidget = new QWidget(this);
	centralWidget->setStyleSheet(windowStyle);
	setCentralWidget(centralWidget);
	winLayout = new QGridLayout(centralWidget);

	dynamicSearchLabel = new QLabel("Quick search: ", this);
	dynamicSearchLabel->setStyleSheet("text-align: center; margin-left: 120px;");
	dynamicSearchBox = new QLineEdit(this);
	dynamicSearchBox->setStyleSheet("margin-bottom: 8px; margin-top:8px; margin-right: 120px;");
	listTitle = new QLabel("<h1>My media library :    </h1>",centralWidget);
	listTitle->setStyleSheet("text-align:center; font-style: italic; margin-top: 10px; margin-left: 220px;");
	objectList = new QListWidget(centralWidget);
	objectList->setSpacing(2);
	objectList->setStyleSheet("padding: 15px; margin: 0px 15px 15px 15px; background-color:#3a3a3a; color:#00DD00;border: 2px solid #FFFFFF");
	scrollArea = new QScrollArea;
	scrollArea->setWidget(objectList);
	insertButton = new QPushButton("Insert Item", centralWidget);
	insertButton->setStyleSheet(buttonStyle);
	insertButton->setMaximumSize(200,50);
	removeButton = new QPushButton("Remove Items", centralWidget );
	removeButton->setStyleSheet(buttonStyle);
	removeButton->setMaximumSize(200,50);
	findButton = new QPushButton("Advanced search", centralWidget);
	findButton->setStyleSheet(buttonStyle);
	findButton->setMaximumSize(200,50);
	saveButton = new QPushButton("Save to file", centralWidget);
	saveButton->setStyleSheet(buttonStyle);
	saveButton->setMaximumSize(200,50);
	loadButton = new QPushButton("Load from file", centralWidget);
	loadButton->setStyleSheet(buttonStyle);
	loadButton->setMaximumSize(200,50);
	refreshButton = new QPushButton("Refresh list", centralWidget);
	refreshButton->setStyleSheet(buttonStyle);
	refreshButton->setMaximumSize(200,50);

	// Layout setting
	winLayout->addWidget(listTitle,0,0,1,3);
	winLayout->addWidget(dynamicSearchLabel,1,0);
	winLayout->addWidget(dynamicSearchBox,1,1,1,2);
	winLayout->addWidget(objectList,2,0,3,3);
	winLayout->addWidget(insertButton,5,0);
	winLayout->addWidget(removeButton,5,1);
	winLayout->addWidget(findButton,5,2);
	winLayout->addWidget(refreshButton,2,3,2,1);
	winLayout->addWidget(saveButton,3,3,2,1);
	winLayout->addWidget(loadButton,4,3,2,1);

	setLayout(winLayout);

	showListFromContainer();

	// Commented to avoid warning, it is an unused variable:
	// QListWidgetItem* toBeModified;   
	findResult = new Qontainer<VideoFile*>();


	// Connect Signals:
	connect(insertButton, SIGNAL(clicked()), this, SLOT(openInsertWindow()));
	connect(removeButton, SIGNAL(clicked()), this, SLOT(windowSelector()));
	connect(findButton, SIGNAL(clicked()), this, SLOT(windowSelector()));
	connect(objectList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(openModifyWindow(QListWidgetItem*)));
	connect(refreshButton, SIGNAL(clicked()), this, SLOT(showListFromContainer()));
	connect(saveButton, SIGNAL(clicked()), this, SLOT (saveContainerToFile()));
	connect(loadButton, SIGNAL(clicked()), this, SLOT(showFromFile()));
	connect(dynamicSearchBox, SIGNAL(textEdited(const QString&)), this, SLOT(quickSearch()));

}

void MainWindow::quickSearch() {
	int elem_num = 0;
	int* itemsIndex = new int[container->getObjCount()];
	std::locale loc;
	string searchKeyword = dynamicSearchBox->text().toStdString();
	string lowercaseKeyword;
	for(string::size_type i=0; i<searchKeyword.size(); i++) {
		lowercaseKeyword += tolower(searchKeyword[i], loc);
	}
	elem_num = container->partialTitleMatch(lowercaseKeyword, itemsIndex);

	findResult = container->returnFromPosition(itemsIndex, elem_num);

	objectList->clear();
	for(unsigned int i=0; i < findResult->getObjCount(); i++) {
		objectList->addItem(new QListWidgetItem(QString::fromStdString((*findResult)[i]->getTitle())));
		}

	// showFindResults(findResult);

	delete[] itemsIndex;
}

void MainWindow::openInsertWindow() {
	objectWindow = new setObjectWidget(container);
	connect(objectWindow, SIGNAL(listUpdated()), this, SLOT(showListFromContainer()));
	(*objectWindow).show();
}

void MainWindow::windowSelector() {
	if (QPushButton* button = dynamic_cast<QPushButton*>(sender())) {
		if(button == removeButton) openSelectWindow(true);
		else if(button == findButton) openSelectWindow(false);
		}

}

void MainWindow::openModifyWindow(QListWidgetItem* item) {
	VideoFile *vid;
	QString text = item->text();
	for(unsigned int i=0; i < container->getObjCount(); i++) {
		if((*container)[i]->getTitle() == text.toStdString()) {
			vid = (*container)[i];
			modifyWindow = new modifyWidget(vid);
			(*modifyWindow).show();
			break;
		}
	}
}

void MainWindow::openSelectWindow(bool remove) {
	findResult->clear();
	searchWindow = new searchByWidget(container, findResult, remove);
	connect(searchWindow, SIGNAL(listUpdated()), this, SLOT(showListFromContainer()));
	connect(searchWindow, SIGNAL(searchComplete(Qontainer<VideoFile*>*)), this, SLOT(showFindResults(Qontainer<VideoFile*>*)));
	(*searchWindow).show();
}

void MainWindow::showListFromContainer() {
	objectList->clear();
	for(unsigned int i=0; i < container->getObjCount(); i++)
	  objectList->addItem(new QListWidgetItem(QString::fromStdString((*container)[i]->getTitle())));
}

void MainWindow::showFromFile() {
	loadFromFile(container, QString("./savedLibrary.json"));
	showListFromContainer();
	QMessageBox loadSuccess;
	loadSuccess.setWindowTitle("Info");
	loadSuccess.setText("Loading from file completed successfully!");
	loadSuccess.exec();
}

void MainWindow::showFindResults(Qontainer<VideoFile*> *results) {
	objectList->clear();
	findResult = results;
	if(findResult->getObjCount() == 0) {
		QMessageBox msgBox;
		msgBox.setWindowTitle("WARNING");
		msgBox.setText("There are no stored elements with this property");
		msgBox.exec();
		showListFromContainer();
	}
	else { 
	for(unsigned int i=0; i < findResult->getObjCount(); i++) {
		objectList->addItem(new QListWidgetItem(QString::fromStdString((*findResult)[i]->getTitle())));
		}
	}
}

void MainWindow::saveContainerToFile() {
	saveToFile(container, "./savedLibrary.json");
	QMessageBox saveSuccess;
	saveSuccess.setWindowTitle("Info");
	saveSuccess.setText("Saving to file completed successfully!");
	saveSuccess.exec();
}

MainWindow::~MainWindow() {

}
