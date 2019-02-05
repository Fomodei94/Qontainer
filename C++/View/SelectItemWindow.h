#ifndef SELECTITEMWINDOW_H
#define SELECTITEMWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>

class SelectItemWindow : public QWidget {
	Q_OBJECT
	private:
		QGridLayout* layout;
		QLabel 	*selectTypeLabel;
		QRadioButton 	*videoFileRadioBtn,
						*movieRadioBtn,
						*tvSerieRadioBtn,
						*animeRadioBtn,
						*matchRadioBtn;
		QPushButton *confirmButton,
					*cancelButton;
		
	public:
		SelectItemWindow(QWidget* parent = nullptr);
		~SelectItemWindow() = default;
		
		
		
};

#endif // SELECTITEMWINDOW_H
