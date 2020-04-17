#include "searchByWidget.h"

searchByWidget::searchByWidget(Qontainer<VideoFile*> *container, Qontainer<VideoFile*> *findResult, bool remove, QWidget *parent) : QWidget(parent), container(container), findResult(findResult) {

	QString functionLabel;
	if(remove) functionLabel = "Remove";
	else functionLabel = "Find";

	setWindowTitle(functionLabel);
	setFixedSize(250,450);

	// Styling parameters
	const QString windowStyle = "background-color:#3a3a3a; color:#FFFFFF;QPushButton{background-color:#2a2a2a; color:#FFFFFF;border: 0.5px solid #AAAAAA; padding: 1px;}";
	const QString buttonStyle = "background-color:#2a2a2a; color:#FFFFFF;border: 0.5px solid #AAAAAA; padding: 1px;";
	const QString disabled = "QWidget:disabled{border: 1px solid #DD0000;}QLineEdit{border: 1px solid #00DD00;}QSpinBox{border: 1px solid #00DD00;}QCheckBox{border: 1px solid #00DD00;}";


	layout = new QGridLayout(this);
	this->setStyleSheet(windowStyle);


	mainLabel = new QLabel("<h3>Search by: </h3>", this);
	mainLabel->setStyleSheet("text-align: center;");

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
	cancelButton->setStyleSheet(buttonStyle);
	confirmButton = new QPushButton(functionLabel, this);
	confirmButton->setStyleSheet(buttonStyle);
	
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
	if(remove)	connect(confirmButton, SIGNAL(clicked()), this, SLOT(removeItems()));
	else {
		connect(confirmButton, SIGNAL(clicked()), this, SLOT(findItems()));
		// connect(searchText, SIGNAL(returnPressed()), this, SLOT(findItems()));  FIX: unstable, may cause segfault.
	}	
}

void searchByWidget::exitWindow() {
	delete this;
}

void searchByWidget::removeItems() {

	if(titleRadioBtn->isChecked())
		container->removeByTitle(searchText->text().toStdString());

	if(genreRadioBtn->isChecked())
		container->removeByGenre(searchText->text().toStdString());

	if(nationRadioBtn->isChecked())
		container->removeByNation(searchText->text().toStdString());

	if(yearRadioBtn->isChecked())
		container->removeByYear(searchSpinbox->value());

	if(directorRadioBtn->isChecked())
		container->removeByDirector(searchText->text().toStdString());

	if(championshipRadioBtn->isChecked())
		container->removeByChampionship(searchText->text().toStdString());

	if(episodesRadioBtn->isChecked())
		container->removeByEpisodes(searchSpinbox->value());

	if(seasonsRadioBtn->isChecked())
		container->removeBySeasons(searchSpinbox->value());

	emit listUpdated();
	exitWindow();

}

void searchByWidget::findItems() {
	int elem_num = 0;
	int* itemsIndex = new int[container->getObjCount()];

	findResult->clear();

	if(titleRadioBtn->isChecked()) {
		std::locale loc;
		string searchKeyword = searchText->text().toStdString();
		string lowercaseKeyword;
		for(string::size_type i=0; i<searchKeyword.size(); i++) {
			lowercaseKeyword += tolower(searchKeyword[i], loc);
		}
		elem_num = container->searchByTitle(lowercaseKeyword, itemsIndex);
	}
		

	else if(genreRadioBtn->isChecked()) {
		std::locale loc;
		string searchKeyword = searchText->text().toStdString();
		string lowercaseKeyword;
		for(string::size_type i=0; i<searchKeyword.size(); i++) {
			lowercaseKeyword += tolower(searchKeyword[i], loc);
		}
		elem_num = container->searchByGenre(lowercaseKeyword, itemsIndex);

	}

	else if(nationRadioBtn->isChecked()) {
		std::locale loc;
		string searchKeyword = searchText->text().toStdString();
		string lowercaseKeyword;
		for(string::size_type i=0; i<searchKeyword.size(); i++) {
			lowercaseKeyword += tolower(searchKeyword[i], loc);
		}
		elem_num = container->searchByNation(lowercaseKeyword, itemsIndex);
	}
		
	else if(directorRadioBtn->isChecked()) {
		std::locale loc;
		string searchKeyword = searchText->text().toStdString();
		string lowercaseKeyword;
		for(string::size_type i=0; i<searchKeyword.size(); i++) {
			lowercaseKeyword += tolower(searchKeyword[i], loc);
		}
		elem_num = container->searchByDirector(lowercaseKeyword, itemsIndex);
	}
		
	else if(championshipRadioBtn->isChecked())
		elem_num = container->searchByChampionship(searchText->text().toStdString(), itemsIndex);

	else if(yearRadioBtn->isChecked())
		elem_num = container->searchByYear(searchSpinbox->value(), itemsIndex);

	else if(episodesRadioBtn->isChecked())
		elem_num = container->searchByEpisodes(searchSpinbox->value(), itemsIndex);

	else if(seasonsRadioBtn->isChecked())
		elem_num = container->searchBySeasons(searchSpinbox->value(), itemsIndex);

	findResult = container->returnFromPosition(itemsIndex, elem_num);

	emit searchComplete(findResult);
	delete[] itemsIndex;
	exitWindow();
}
