#include "modifyWidget.h"
#include <iostream>
#include<QMessageBox>

modifyWidget::modifyWidget(VideoFile *vid, QWidget* parent) : QWidget(parent), vid(vid) {
	setWindowTitle("View specific item");
	setFixedSize(380,700);

	layout = new QGridLayout(this);

	mainLabel = new QLabel(QString("<h2>View/Modify item</h2>"), this);

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
	confirmButton = new QPushButton("Modify item", this);

	layout->addWidget(mainLabel,0,0,1,4);
	//layout->addWidget(objSelector,1,0,1,3);
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
	lengthSpinbox->setEnabled(false);
	episodesSpinbox->setEnabled(false);
	animeFinCheckbox->setEnabled(false);
	seasonsSpinbox->setEnabled(false);
	serieFinCheckbox->setEnabled(false);
	championshipText->setEnabled(false);
	homeTeamText->setEnabled(false);
	guestTeamText->setEnabled(false);

  activateFields();
  fillFields();

	connect(cancelButton, SIGNAL(clicked()), this, SLOT(exitWindow()));
	connect(confirmButton, SIGNAL(clicked()), this, SLOT(confirmModify()));
}

void modifyWidget::exitWindow() {
	delete this;
}

void modifyWidget::activateFields() {

  if(dynamic_cast<Movie*>(vid)) {
    directorText->setEnabled(true);
    lengthSpinbox->setEnabled(true);
  }

  else if(dynamic_cast<SportMatch*>(vid)) {
    championshipText->setEnabled(true);
    homeTeamText->setEnabled(true);
    guestTeamText->setEnabled(true);
  }

  else if(dynamic_cast<TvSerie*>(vid)) {
    seasonsSpinbox->setEnabled(true);
    serieFinCheckbox->setEnabled(true);
  }

  else if(dynamic_cast<Anime*>(vid)) {
    episodesSpinbox->setEnabled(true);
    animeFinCheckbox->setEnabled(true);
  }
}

void modifyWidget::fillFields() const {
  QString tit = tit.fromStdString(vid->getTitle());
  titleText->setText(tit);
  QString gen = gen.fromStdString(vid->getGenre());
  genreText->setText(gen);
  QString nat = nat.fromStdString(vid->getNation());
  nationText->setText(nat);
  yearSpinbox->setValue(vid->getPublishingYear());

  if(dynamic_cast<Movie*>(vid)) {
    Movie* aux = dynamic_cast<Movie*>(vid);
    QString direc = direc.fromStdString(aux->getDirector());
    directorText->setText(direc);
    lengthSpinbox->setValue(aux->getLength());
  }

  else if(dynamic_cast<SportMatch*>(vid)) {
    SportMatch* aux = dynamic_cast<SportMatch*>(vid);
    QString champ = champ.fromStdString(aux->getChampionship());
    championshipText->setText(champ);
    QString homeT = homeT.fromStdString(aux->getHomeTeam());
    homeTeamText->setText(homeT);
    QString guestT = guestT.fromStdString(aux->getGuestTeam());
    guestTeamText->setText(guestT);
  }

  else if(dynamic_cast<TvSerie*>(vid)) {
    TvSerie* aux = dynamic_cast<TvSerie*>(vid);
    seasonsSpinbox->setValue(aux->getSeasons());
    serieFinCheckbox->setChecked(aux->isFinished());
  }

  else if(dynamic_cast<Anime*>(vid)) {
    Anime* aux = dynamic_cast<Anime*>(vid);
    episodesSpinbox->setValue(aux->getEpisodes());
    animeFinCheckbox->setChecked(aux->isFinished());
  }
}

void modifyWidget::confirmModify() {

  vid->setTitle(titleText->text().toStdString());
  vid->setGenre(genreText->text().toStdString());
  vid->setNation(nationText->text().toStdString());
  vid->setPublishingYear(yearSpinbox->value());

  if(dynamic_cast<Movie*>(vid)) {
    Movie* aux = dynamic_cast<Movie*>(vid);
    aux->setDirector(directorText->text().toStdString());
    aux->setLength(lengthSpinbox->value());
  }

  else if(dynamic_cast<SportMatch*>(vid)) {
    SportMatch* aux = dynamic_cast<SportMatch*>(vid);
    aux->setChampionship(championshipText->text().toStdString());
    aux->setHomeTeam(homeTeamText->text().toStdString());
    aux->setGuestTeam(guestTeamText->text().toStdString());
  }

  else if(dynamic_cast<TvSerie*>(vid)) {
    TvSerie* aux = dynamic_cast<TvSerie*>(vid);
    aux->setSeasons(seasonsSpinbox->value());
    aux->setFinished(serieFinCheckbox->isChecked());
  }

  else if(dynamic_cast<Anime*>(vid)) {
    Anime* aux = dynamic_cast<Anime*>(vid);
    aux->setEpisodes(episodesSpinbox->value());
    aux->setFinished(animeFinCheckbox->isChecked());
  }

	/*  MODIFY CONFIRMED INFO MESSAGEBOX (optional)
	QMessageBox msgBox;
	msgBox.setWindowTitle("INFO");
	msgBox.setText("Item modification went well!");
	msgBox.exec();
	*/

	emit listUpdated();
	exitWindow();
}
