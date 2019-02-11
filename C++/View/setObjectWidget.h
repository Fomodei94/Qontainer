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

class setObjectWidget : public QWidget {
	Q_OBJECT
	private:
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
				*lenghtLabel,
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
					*lenghtSpinbox,
					*episodesSpinbox,
					*seasonsSpinbox;
					
		QCheckBox	*animeFinCheckbox,
					*serieFinCheckbox;

		QPushButton	*cancelButton,
					*confirmButton;
		
	public:
		setObjectWidget(const QString& func, QWidget* parent = nullptr);
		
	public slots:
		void exitWindow();
		void confirmInsertion();
		void confirmRemoval();
		void confirmSearch();
};

#endif // SETOBJECTWIDGET_H
