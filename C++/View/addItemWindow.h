#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

class addItemWindow : public QWidget {
	private:
		QGridLayout* layout;
		QLabel 	*videoFileLabel,
				*titleLabel,
				*genreLabel,
				*pubDateLabel,
				*nationLabel,
				*movieLabel
		
	public:
	
};

#endif // ADDITEMWINDOW_H
