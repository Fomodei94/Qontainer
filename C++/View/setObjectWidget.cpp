#include "setObjectWidget.h"

setObjectWidget::setObjectWidget(const QString& func, QWidget* parent) : QWidget(parent) {
	setWindowTitle("Select item(s) type");
	setFixedSize(400,650);
	
	layout = new QGridLayout(this);
	
	mainLabel = new QLabel(QString("<h4>Select which file type to %1:</h4>").arg(func), this);
	genericVideoLabel = new QLabel("Generic video file info:", this);
	movieLabel = new QLabel("Movie specific info:", this);
	animeLabel = new QLabel("Anime specific info:", this);
	tvSerieLabel = new QLabel("Tv serie specific info:", this);
	matchLabel = new QLabel("Sport match specific info:", this);
	titleLabel = new QLabel("Title: ", this);
	genreLabel = new QLabel("Genre: ", this);
	nationLabel = new QLabel("Nation: ", this);
	yearLabel = new QLabel("Year: ", this);
	
	objSelector = new QComboBox(this);
	objSelector->addItem("Generic Video File");
	objSelector->addItem("Movie");
	objSelector->addItem("Anime");
	objSelector->addItem("Tv Serie");
	objSelector->addItem("Sport Match");
	
	titleText = new QLineEdit("Title", this);
	genreText = new QLineEdit("Genre", this);
	nationText = new QLineEdit("Nation", this);
	yearSpinbox = new QSpinBox(this);
	yearSpinbox-> setRange(1890,9999);
	
	layout->addWidget(mainLabel,0,0,1,2);
	layout->addWidget(objSelector,1,0,1,2);
	layout->addWidget(genericVideoLabel,2,0,1,2);
	layout->addWidget(titleLabel,3,0);
	layout->addWidget(titleText,3,1);
	layout->addWidget(genreLabel,3,2);
	layout->addWidget(genreText,3,3);
	layout->addWidget(nationLabel,4,0);
	layout->addWidget(nationText,4,1);
	layout->addWidget(yearLabel,4,2);
	layout->addWidget(yearSpinbox,4,3);
	setLayout(layout);
}
