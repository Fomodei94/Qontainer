#include "VideoFile.h"

//  GETTERS
string VideoFile::getTitle() {
	return title;
}

string VideoFile::getGenre() {
	return genre;
}

string VideoFile::getNation() {
	return nation;
}

Date VideoFile::getPublishingDate() {
	return publishingDate;
}

//  SETTERS
void VideoFile::setTitle(string tit) {
	// CONTROLLO SULLA LUNGHEZZA STRINGA QUI !!!
	title = tit;
}

void VideoFile::setGenre(string gen) {
	// CONTROLLO LUNGHEZZA STRINGA QUI !!!
	genre = gen;
}

void VideoFile::setPublishingDate(Date dat) {
	publishingDate = dat;
}

void VideoFile::setNation(string nat) {
	// CONTROLLO SULLA LUNGHEZZA STRINGA QUI !!!
	nation = nat;
}
