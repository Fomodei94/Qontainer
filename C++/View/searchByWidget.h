#ifndef SEARCH_BY_WIDGET_H
#define SEARCH_BY_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QFrame>
#include "../Model/Qontainer.h"
#include "../Model/VideoFile.h"

class searchByWidget : public QWidget {
	Q_OBJECT
	private:
		Qontainer<VideoFile*> *container,
													*findResult;
		QGridLayout	*layout;
		QLabel	*mainLabel,
				*keywordLabel;
		QRadioButton	*titleRadioBtn,
						*genreRadioBtn,
						*nationRadioBtn,
						*yearRadioBtn,
						*directorRadioBtn,
						*episodesRadioBtn,
						*seasonsRadioBtn,
						*championshipRadioBtn;

		QLineEdit	*searchText;
		QSpinBox	*searchSpinbox;
		QFrame	*separator1,
				*separator2;
		QPushButton	*cancelButton,
					*confirmButton;

	public:
		searchByWidget(Qontainer<VideoFile*> *container, Qontainer<VideoFile*> *findResult, bool remove, QWidget *parent = 0);

	signals:
		void listUpdated();
		void searchComplete();

	public slots:
		void exitWindow();
		void removeItems();
		void findItems();

};

#endif //SEARCH_BY_WIDGET_H
