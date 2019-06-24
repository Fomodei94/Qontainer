#include "setObjectWidget.h"
#include <iostream>
#include<QMessageBox>

setObjectWidget::setObjectWidget(Qontainer<VideoFile*> *container, QWidget* parent) : QWidget(parent), container(container) {
	setWindowTitle("Select item(s) type");
	setFixedSize(380,700);

	// Styling parameters
	const QString windowStyle = "background-color:#3a3a3a; color:#FFFFFF;";
	const QString buttonStyle = "background-color:#2a2a2a; color:#FFFFFF;border: 0.5px solid #AAAAAA; padding: 1px;";
	const QString disabled = "QWidget:disabled{border: 1px solid #DD0000;}QLineEdit{border: 1px solid #00DD00;}QSpinBox{border: 1px solid #00DD00;}QCheckBox{border: 1px solid #00DD00;}";

	layout = new QGridLayout(this);

	this->setStyleSheet(windowStyle);
	mainLabel = new QLabel(QString("<h2>Select which file type to insert:</h2>"), this);
	mainLabel->setStyleSheet("font-style: italic; margin: 10px 15px 0px 0px;");

	objSelector = new QComboBox(this);
	objSelector->addItem("Generic Video File");
	objSelector->addItem("Movie");
	objSelector->addItem("Anime");
	objSelector->addItem("Tv Serie");
	objSelector->addItem("Sport Match");

	genericVideoLabel = new QLabel("<h3>Generic video file info:</h3>", this);
	titleLabel = new QLabel("Title:", this);
	titleText = new QLineEdit(this);
	titleText->setStyleSheet(disabled);
	genreLabel = new QLabel("Genre:", this);
	genreText = new QLineEdit(this);
	genreText->setStyleSheet(disabled);
	nationLabel = new QLabel("Nation:", this);
	nationText = new QLineEdit(this);
	nationText->setStyleSheet(disabled);
	yearLabel = new QLabel("Year:", this);
	yearSpinbox = new QSpinBox(this);
	yearSpinbox-> setRange(1890,9999);
	yearSpinbox->setStyleSheet(disabled);

	movieLabel = new QLabel("<h3>Movie specific info:</h3>", this);
	directorLabel = new QLabel("Director:", this);
	directorText = new QLineEdit(this);
	lengthLabel = new QLabel("Length (min):", this);
	lengthSpinbox = new QSpinBox(this);
	lengthSpinbox->setRange(1,999);

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
	cancelButton->setStyleSheet(buttonStyle);
	confirmButton = new QPushButton("Insert", this);
	confirmButton->setStyleSheet(buttonStyle);

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
	layout->addWidget(lengthLabel,6,3);
	layout->addWidget(lengthSpinbox,6,4);
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

	directorText->setEnabled(false);
	directorText->setStyleSheet(disabled);
	lengthSpinbox->setEnabled(false);
	lengthSpinbox->setStyleSheet(disabled);
	episodesSpinbox->setEnabled(false);
	episodesSpinbox->setStyleSheet(disabled);
	animeFinCheckbox->setEnabled(false);
	animeFinCheckbox->setStyleSheet(disabled);
	seasonsSpinbox->setEnabled(false);
	seasonsSpinbox->setStyleSheet(disabled);
	serieFinCheckbox->setEnabled(false);
	serieFinCheckbox->setStyleSheet(disabled);
	championshipText->setEnabled(false);
	championshipText->setStyleSheet(disabled);
	homeTeamText->setEnabled(false);
	homeTeamText->setStyleSheet(disabled);
	guestTeamText->setEnabled(false);
	guestTeamText->setStyleSheet(disabled);

	connect(cancelButton, SIGNAL(clicked()), this, SLOT(exitWindow()));
	connect(objSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(disableFields()));
	connect(confirmButton, SIGNAL(clicked()), this, SLOT(confirmInsertion()));
}

void setObjectWidget::exitWindow() {
	delete this;
}

void setObjectWidget::disableFields() {
	switch(objSelector->currentIndex()) {
		case 0:
			directorText->setEnabled(false);
			lengthSpinbox->setEnabled(false);
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
			lengthSpinbox->setEnabled(true);
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
			lengthSpinbox->setEnabled(false);
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
			lengthSpinbox->setEnabled(false);
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
			lengthSpinbox->setEnabled(false);
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
	VideoFile *vid;
	switch(objSelector->currentIndex()) {
		case 0:
			vid = new VideoFile(titleText->text().toStdString(), genreText->text().toStdString(),
								nationText->text().toStdString(), yearSpinbox->value());
			break;
		case 1:
			vid = new Movie(titleText->text().toStdString(), genreText->text().toStdString(),
							nationText->text().toStdString(), yearSpinbox->value(),
							directorText->text().toStdString(), lengthSpinbox->value());
			break;
		case 2:
			vid = new Anime(titleText->text().toStdString(), genreText->text().toStdString(),
							nationText->text().toStdString(), yearSpinbox->value(),
							episodesSpinbox->value(), animeFinCheckbox->isChecked());
			break;
		case 3:
			vid = new TvSerie(titleText->text().toStdString(), genreText->text().toStdString(),
							nationText->text().toStdString(), yearSpinbox->value(),
							seasonsSpinbox->value(), serieFinCheckbox->isChecked());
			break;
		case 4:
			vid = new SportMatch(titleText->text().toStdString(), genreText->text().toStdString(),
								nationText->text().toStdString(), yearSpinbox->value(),
								championshipText->text().toStdString(), homeTeamText->text().toStdString(),
								guestTeamText->text().toStdString());
			break;
	}
	container->pushBack(vid);

	/*  INSERTION CONFIRMED INFO MESSAGEBOX (optional)
	QMessageBox msgBox;
	msgBox.setWindowTitle("INFO");
	msgBox.setText("Insertion went well!");
	msgBox.exec();
	*/

	for(int i=0; i<container->getObjCount(); i++) {	// For terminal logging purpose.
			std::cout<<"Element "<<i<<" title: "<<(*container)[i]->getTitle()<<std::endl;
		}
	emit listUpdated();
	exitWindow();
}
