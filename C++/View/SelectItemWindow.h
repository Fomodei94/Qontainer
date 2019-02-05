#ifndef SELECTITEMWINDOW_H
#define SELECTITEMWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>

class SelectItemWindow : public QWidget {
	
	private:
		QGridLayout* layout;
		QLabel 	*selectTypeLabel,
				*videoFileLabel,
				*movieLabel,
				*tvSerieLabel,
				*animeLabel,
				*matchLabel;
		
		
	public:
	
};

#endif // SELECTITEMWINDOW_H
