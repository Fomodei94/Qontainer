#ifndef SETOBJECTWIDGET_H
#define SETOBJECTWIDGET_H

#include <QGridLayout>
#include <QComboBox>
#include <QString>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QCheckBox>

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
				*seasonsLabel;
				
		QLineEdit	*titleText,
					*genreText,
					*nationText,
					*directorText;
					
		QSpinBox	*yearSpinbox,
					*lenghtSpinbox,
					*episodesSpinbox,
					*seasonsSpinbox;
					
		QCheckBox	*animeFinCheckbox,
					*serieFinCheckbox;
		
	public:
		setObjectWidget(const QString& func, QWidget* parent = nullptr);
		
	public slots:
		
};

#endif // SETOBJECTWIDGET_H
