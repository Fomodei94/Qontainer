#ifndef SETOBJECTWIDGET_H
#define SETOBJECTWIDGET_H

#include <QGridLayout>
#include <QComboBox>
#include <QString>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include "../Model/Qontainer.h"
#include "../Model/VideoFile.h"
#include "../Model/Movie.h"
#include "../Model/Anime.h"
#include "../Model/TvSerie.h"
#include "../Model/SportMatch.h"
#include <string>

class setObjectWidget : public QWidget {
	Q_OBJECT
	private:

		Qontainer<VideoFile> *container;

		QGridLayout *layout;
		
		QComboBox *objSelector;
		
		QLabel	*mainLabel,
				*genericVideoLabel,
				*movieLabel,
				*animeLabel,
				*tvSerieLabel,
				*matchLabel,
				*titleLabel,
				*genreLabel,
				*nationLabel,
				*yearLabel,
				*directorLabel,
				*lengthLabel,
				*animeFinLabel,
				*episodesLabel,
				*serieFinLabel,
				*seasonsLabel,
				*championshipLabel,
				*homeTeamLabel,
				*guestTeamLabel;
				
		QLineEdit	*titleText,
					*genreText,
					*nationText,
					*directorText,
					*championshipText,
					*homeTeamText,
					*guestTeamText;
					
		QSpinBox	*yearSpinbox,
					*lengthSpinbox,
					*episodesSpinbox,
					*seasonsSpinbox;
					
		QCheckBox	*animeFinCheckbox,
					*serieFinCheckbox;

		QPushButton	*cancelButton,
					*confirmButton;
		
	public:
		setObjectWidget(Qontainer<VideoFile> *container, QWidget* parent = nullptr);
		
	public slots:
		void exitWindow();
		void disableFields();
		void confirmInsertion();
		void confirmRemoval();
		void confirmSearch(); 
};

#endif // SETOBJECTWIDGET_H
