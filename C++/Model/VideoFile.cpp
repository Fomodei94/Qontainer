#include "VideoFile.h"



string getTitle() {
	return title;
}

string getGenre() {
	return genre;
}

string getNation() {
	return nation;
}

Date getPublishingDate() {
	return publishingDate;
}

void setTitle(string tit) {
	// CONTROLLO SULLA LUNGHEZZA STRINGA QUI !!!
	title = tit;
}
