#include "setObjectWidget.h"

setObjectWidget::setObjectWidget(Qontainer<VideoFile> *container, const QString& func, QWidget* parent) : QWidget(parent), container(container) {
	setWindowTitle("Select item(s) type");
	setFixedSize(380,700);
	
	layout = new QGridLayout(this);
	
	mainLabel = new QLabel(QString("<h2>Select which file type to %1:</h2>").arg(func), this);
	
	objSelector = new QComboBox(this);
	objSelector->addItem("Generic Video File");
	objSelector->addItem("Movie");
	objSelector->addItem("Anime");
	objSelector->addItem("Tv Serie");
	objSelector->addItem("Sport Match");
	
	genericVideoLabel = new QLabel("<h3>Generic video file info:</h3>", this);
	titleLabel = new QLabel("Title:", this);
	titleText = new QLineEdit(this);
	genreLabel = new QLabel("Genre:", this);
	genreText = new QLineEdit(this);
	nationLabel = new QLabel("Nation:", this);
	nationText = new QLineEdit(this);
	yearLabel = new QLabel("Year:", this);
	yearSpinbox = new QSpinBox(this);
	yearSpinbox-> setRange(1890,9999);
	
	movieLabel = new QLabel("<h3>Movie specific info:</h3>", this);
	directorLabel = new QLabel("Director:", this);
	directorText = new QLineEdit(this);
	lenghtLabel = new QLabel("Lenght (min):", this);
	lenghtSpinbox = new QSpinBox(this);
	lenghtSpinbox->setRange(1,999);
	
	animeLabel = new QLabel("<h3>Anime specific info:</h3>", this);
	episodesLabel = new QLabel("Episodes number:", this);
	episodesSpinbox = new QSpinBox(this);
	episodesSpinbox-> setRange(1,999);
	animeFinLabel = new QLabel("It's over:", this);
	animeFinCheckbox = new QCheckBox(this);
	
	tvSerieLabel = new QLabel("<h3>Tv serie specific info:</h3>", this);
	seasonsLabel = new QLabel("Seasons number:", this);
	seasonsSpinbox = new QSpinBox(this);
	seasonsSpinbox->setRange(1,99);
	serieFinLabel = new QLabel("It's over:", this);
	serieFinCheckbox = new QCheckBox(this);
	
	matchLabel = new QLabel("<h3>Sport match specific info:</h3>", this);
	championshipLabel = new QLabel("Championship:", this);
	championshipText = new QLineEdit(this);
	homeTeamLabel = new QLabel("Home team:", this);
	homeTeamText = new QLineEdit(this);
	guestTeamLabel = new QLabel("Guest team:", this);
	guestTeamText = new QLineEdit(this);
	
	cancelButton = new QPushButton("Cancel", this);
	confirmButton = new QPushButton(func, this);
	
	layout->addWidget(mainLabel,0,0,1,4);
	layout->addWidget(objSelector,1,0,1,3);
	layout->addWidget(genericVideoLabel,2,0,1,4);
	layout->addWidget(titleLabel,3,0);
	layout->addWidget(titleText,3,1,1,2);
	layout->addWidget(genreLabel,3,3);
	layout->addWidget(genreText,3,4,1,2);
	layout->addWidget(nationLabel,4,0);
	layout->addWidget(nationText,4,1,1,2);
	layout->addWidget(yearLabel,4,3);
	layout->addWidget(yearSpinbox,4,4);
	layout->addWidget(movieLabel,5,0,1,4);
	layout->addWidget(directorLabel,6,0);
	layout->addWidget(directorText,6,1,1,2);
	layout->addWidget(lenghtLabel,6,3);
	layout->addWidget(lenghtSpinbox,6,4);
	layout->addWidget(animeLabel,7,0,1,4);
	layout->addWidget(episodesLabel,8,0,1,2);
	layout->addWidget(episodesSpinbox,8,2);
	layout->addWidget(animeFinLabel,8,3);
	layout->addWidget(animeFinCheckbox,8,4);
	layout->addWidget(tvSerieLabel,9,0,1,4);
	layout->addWidget(seasonsLabel,10,0,1,2);
	layout->addWidget(seasonsSpinbox,10,2);
	layout->addWidget(serieFinLabel,10,3);
	layout->addWidget(serieFinCheckbox,10,4);
	layout->addWidget(matchLabel,11,0,1,4);
	layout->addWidget(championshipLabel,12,0,1,2);
	layout->addWidget(championshipText,12,2,1,2);
	layout->addWidget(homeTeamLabel,13,0);
	layout->addWidget(homeTeamText,13,1,1,2);
	layout->addWidget(guestTeamLabel,13,3);
	layout->addWidget(guestTeamText,13,4,1,2);
	layout->addWidget(cancelButton,14,1,1,2);
	layout->addWidget(confirmButton,14,3,1,2);
	layout->setVerticalSpacing(20);
	setLayout(layout);
	
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(exitWindow()));
	connect(objSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(disableFields()));
	if(func=="Insert") connect(confirmButton, SIGNAL(clicked()), this, SLOT(confirmInsertion()));
	if(func=="Remove") connect(confirmButton, SIGNAL(clicked()), this, SLOT(confirmRemoval()));
	if(func=="Find") connect(confirmButton, SIGNAL(clicked()), this, SLOT(confirmSearch()));
}

void setObjectWidget::exitWindow() {
	delete this;
}

void setObjectWidget::disableFields() {
	switch(objSelector->currentIndex()) {
		case 0:
			directorText->setEnabled(false);
			lenghtSpinbox->setEnabled(false);
			episodesSpinbox->setEnabled(false);
			animeFinCheckbox->setEnabled(false);
			seasonsSpinbox->setEnabled(false);
			serieFinCheckbox->setEnabled(false);
			championshipText->setEnabled(false);
			homeTeamText->setEnabled(false);
			guestTeamText->setEnabled(false);
			break;
		case 1:
			directorText->setEnabled(true);
			lenghtSpinbox->setEnabled(true);
			episodesSpinbox->setEnabled(false);
			animeFinCheckbox->setEnabled(false);
			seasonsSpinbox->setEnabled(false);
			serieFinCheckbox->setEnabled(false);
			championshipText->setEnabled(false);
			homeTeamText->setEnabled(false);
			guestTeamText->setEnabled(false);			
			break;
		case 2:
			directorText->setEnabled(false);
			lenghtSpinbox->setEnabled(false);
			episodesSpinbox->setEnabled(true);
			animeFinCheckbox->setEnabled(true);
			seasonsSpinbox->setEnabled(false);
			serieFinCheckbox->setEnabled(false);
			championshipText->setEnabled(false);
			homeTeamText->setEnabled(false);
			guestTeamText->setEnabled(false);		
			break;
		case 3:
			directorText->setEnabled(false);
			lenghtSpinbox->setEnabled(false);
			episodesSpinbox->setEnabled(false);
			animeFinCheckbox->setEnabled(false);
			seasonsSpinbox->setEnabled(true);
			serieFinCheckbox->setEnabled(true);
			championshipText->setEnabled(false);
			homeTeamText->setEnabled(false);
			guestTeamText->setEnabled(false);
			break;
		case 4:
			directorText->setEnabled(false);
			lenghtSpinbox->setEnabled(false);
			episodesSpinbox->setEnabled(false);
			animeFinCheckbox->setEnabled(false);
			seasonsSpinbox->setEnabled(false);
			serieFinCheckbox->setEnabled(false);
			championshipText->setEnabled(true);
			homeTeamText->setEnabled(true);
			guestTeamText->setEnabled(true);
			break;
	}
}

void setObjectWidget::confirmInsertion() {
	VideoFile* vid = new VideoFile("prova", "prova", "prova", 2010);
	container->pushBack(vid);
	//delete vid;
}

void setObjectWidget::confirmRemoval() {
	
}

void setObjectWidget::confirmSearch() {
	
}
