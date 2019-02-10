#include "setObjectWidget.h"

setObjectWidget::setObjectWidget(const QString& func, QWidget* parent) : QWidget(parent) {
	setWindowTitle("Select item(s) type");
	setFixedSize(320,650);
	
	layout = new QGridLayout(this);
	
	mainLabel = new QLabel(QString("<h3>Select which file type to %1:</h3>").arg(func), this);

	
	matchLabel = new QLabel("<h4>Sport match specific info:</h4>", this);
	
	objSelector = new QComboBox(this);
	objSelector->addItem("Generic Video File");
	objSelector->addItem("Movie");
	objSelector->addItem("Anime");
	objSelector->addItem("Tv Serie");
	objSelector->addItem("Sport Match");
	
	genericVideoLabel = new QLabel("<h4>Generic video file info:</h4>", this);
	titleLabel = new QLabel("Title: ", this);
	titleText = new QLineEdit(this);
	genreLabel = new QLabel("Genre: ", this);
	genreText = new QLineEdit(this);
	nationLabel = new QLabel("Nation: ", this);
	nationText = new QLineEdit(this);
	yearLabel = new QLabel("Year: ", this);
	yearSpinbox = new QSpinBox(this);
	yearSpinbox-> setRange(1890,9999);
	
	movieLabel = new QLabel("<h4>Movie specific info:</h4>", this);
	directorLabel = new QLabel("Director: ", this);
	directorText = new QLineEdit(this);
	lenghtLabel = new QLabel("Lenght (min): ", this);
	lenghtSpinbox = new QSpinBox(this);
	lenghtSpinbox->setRange(1,999);
	
	animeLabel = new QLabel("<h4>Anime specific info:</h4>", this);
	episodesLabel = new QLabel("Episodes number: ", this);
	episodesSpinbox = new QSpinBox(this);
	episodesSpinbox-> setRange(1,999);
	animeFinLabel = new QLabel("Is over: ", this);
	animeFinCheckbox = new QCheckBox(this);
	
	tvSerieLabel = new QLabel("<h4>Tv serie specific info:</h4>", this);
	seasonsLabel = new QLabel("Seasons number: ", this);
	seasonsSpinbox = new QSpinBox(this);
	seasonsSpinbox->setRange(1,99);
	serieFinLabel = new QLabel("Is over: ", this);
	serieFinCheckbox = new QCheckBox(this);
	
	layout->addWidget(mainLabel,0,0,1,4);
	layout->addWidget(objSelector,1,0,1,2);
	layout->addWidget(genericVideoLabel,2,0,1,4);
	layout->addWidget(titleLabel,3,0);
	layout->addWidget(titleText,3,1);
	layout->addWidget(genreLabel,3,2);
	layout->addWidget(genreText,3,3);
	layout->addWidget(nationLabel,4,0);
	layout->addWidget(nationText,4,1);
	layout->addWidget(yearLabel,4,2);
	layout->addWidget(yearSpinbox,4,3);
	layout->addWidget(movieLabel,5,0,1,4);
	layout->addWidget(directorLabel,6,0);
	layout->addWidget(directorText,6,1);
	layout->addWidget(lenghtLabel,6,2);
	layout->addWidget(lenghtSpinbox,6,3);
	layout->addWidget(animeLabel,7,0,1,4);
	layout->addWidget(episodesLabel,8,0);
	layout->addWidget(episodesSpinbox,8,1);
	layout->addWidget(animeFinLabel,8,2);
	layout->addWidget(animeFinCheckbox,8,3);
	layout->addWidget(tvSerieLabel,9,0,1,4);
	layout->addWidget(seasonsLabel,10,0);
	layout->addWidget(seasonsSpinbox,10,1);
	layout->addWidget(serieFinLabel,10,2);
	layout->addWidget(serieFinCheckbox,10,3);
	setLayout(layout);
}
