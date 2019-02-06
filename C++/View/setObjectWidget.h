#ifndef SETOBJECTWIDGET_H
#define SETOBJECTWIDGET_H

#include <QGridLayout>
#include <QComboBox>
#include <QString>
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>

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
				*yearLabel;
		QLineEdit	*titleText,
					*genreText,
					*nationText;
		QSpinBox	*yearSpinbox;
		
	public:
		setObjectWidget(const QString& func, QWidget* parent = nullptr);
};

#endif // SETOBJECTWIDGET_H
