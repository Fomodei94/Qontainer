#include "SelectItemWindow.h"

SelectItemWindow::SelectItemWindow(QWidget* parent) : QWidget(parent) {
	setWindowTitle("Select Item Type");
	setFixedSize(300,350);
	setModal(true);
	
	layout = new QGridLayout(this);
	
	selectTypeLabel = new QLabel("<h4>Select which file type to add:</h4>", this);
	videoFileRadioBtn = new QRadioButton("Generic Video", this);
	movieRadioBtn = new QRadioButton("Movie", this);
	tvSerieRadioBtn = new QRadioButton("Tv Serie", this);
	animeRadioBtn = new QRadioButton("Anime", this);
	matchRadioBtn = new QRadioButton("Sport Match", this);
	cancelButton = new QPushButton("Cancel", this);
	confirmButton = new QPushButton("Ok", this);
	
	layout->addWidget(selectTypeLabel,0,0,1,2);
	layout->addWidget(videoFileRadioBtn,1,0);
	layout->addWidget(movieRadioBtn,2,0);
	layout->addWidget(tvSerieRadioBtn,3,0);
	layout->addWidget(animeRadioBtn,4,0);
	layout->addWidget(matchRadioBtn,5,0);
	layout->addWidget(cancelButton,6,0);
	layout->addWidget(confirmButton,6,1);
	setLayout(layout);
}
