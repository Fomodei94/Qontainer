#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include <QGridLayout>
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

class modifyWidget : public QWidget {
	Q_OBJECT
	private:

		VideoFile *vid;

		QGridLayout *layout;

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
		modifyWidget(VideoFile* vid, QWidget* parent = nullptr);

	signals:
		void listUpdated();

	public slots:
		void exitWindow();
		void activateFields();
    void fillFields() const;
		void confirmModify();

};

#endif // MODIFYWIDGET_H
