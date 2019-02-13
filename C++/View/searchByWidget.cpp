#include "searchByWidget.h"

searchByWidget::searchByWidget(Qontainer<VideoFile*> *container, bool remove, QWidget *parent) : QWidget(parent), container(container) {
	
	QString functionLabel;
	if(remove) functionLabel = "Remove";
	else functionLabel = "Find";
	
	setWindowTitle(functionLabel);
	setFixedSize(250,450);
	
	layout = new QGridLayout(this);
	
	mainLabel = new QLabel("<h3>Search by: </h3>", this);
	
	titleRadioBtn = new QRadioButton("Title", this);
	titleRadioBtn->setChecked(true);
	genreRadioBtn = new QRadioButton("Genre", this);
	nationRadioBtn = new QRadioButton("Nation", this);
	directorRadioBtn = new QRadioButton("Director", this);
	championshipRadioBtn = new QRadioButton("Championship", this);
	
	keywordLabel = new QLabel("Keyword:", this);
	searchText = new QLineEdit(this);
	
	separator1 = new QFrame(this);
	separator1->setFrameShape(QFrame::HLine);
	separator2 = new QFrame(this);
	separator2->setFrameShape(QFrame::HLine);
	
	yearRadioBtn = new QRadioButton("Year", this);
	episodesRadioBtn = new QRadioButton("Episodes num", this);
	seasonsRadioBtn = new QRadioButton("Seasons num", this);
	searchSpinbox = new QSpinBox(this);
	searchSpinbox->setRange(1,9999);
	
	cancelButton = new QPushButton("Cancel", this);
	confirmButton = new QPushButton(functionLabel, this);
	
	layout->addWidget(mainLabel,0,0,1,4);
	layout->addWidget(titleRadioBtn,1,0,1,2);
	layout->addWidget(genreRadioBtn,1,2,1,2);
	layout->addWidget(nationRadioBtn,2,0,1,2);
	layout->addWidget(directorRadioBtn,2,2,1,2);
	layout->addWidget(championshipRadioBtn,3,0,1,3);
	layout->addWidget(keywordLabel,4,0);
	layout->addWidget(searchText,4,1,1,3);
	layout->addWidget(separator1,5,0,1,4);
	layout->addWidget(yearRadioBtn,6,0,1,2);
	layout->addWidget(episodesRadioBtn,6,2,1,2);
	layout->addWidget(seasonsRadioBtn,7,0,1,2);
	layout->addWidget(searchSpinbox,8,1,1,2);
	layout->addWidget(separator2,9,0,1,4);
	layout->addWidget(cancelButton,10,2);
	layout->addWidget(confirmButton,10,3);
	layout->setVerticalSpacing(20);
	setLayout(layout);
	
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(exitWindow()));
	if(remove) connect(confirmButton, SIGNAL(clicked()), this, SLOT(removeItems()));
	else connect(confirmButton, SIGNAL(clicked()), this, SLOT(findItems()));
	
	
}

void searchByWidget::exitWindow() {
	delete this;
}

void searchByWidget::removeItems() {
	
	int elem_num = 0;
	int* itemsIndex;
	
	if(titleRadioBtn->isChecked()) elem_num = container->searchByTitle(searchText->text(), itemsIndex);
	if(genreRadioBtn->isChecked()) elem_num = container->searchByGenre(searchText->text(), itemsIndex);
	if(nationRadioBtn->isChecked()) elem_num = container->searchByNation(searchText->text(), itemsIndex);
	if(directorRadioBtn->isChecked()) elem_num = container->searchByDirector(searchText->text(), itemsIndex);
	if(championshipRadioBtn->isChecked()) elem_num = container->searchByChampionship(searchText->text(), itemsIndex);
	if(yearRadioBtn->isChecked()) elem_num = container->searchByYear(searchSpinbox->value(), itemsIndex);
	if(episodesRadioBtn->isChecked()) elem_num = container->searchByEpisodes(searchSpinbox->value(), itemsIndex);
	if(seasonsRadioBtn->isChecked()) elem_num = container->searchBySeasons(searchSpinbox->value(), itemsIndex);
}

void searchByWidget::findItems() {
	
}
