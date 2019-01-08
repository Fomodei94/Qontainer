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

int VideoFile::getPublishingYear() {
	return publishingYear;
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

void VideoFile::setPublishingYear(int year) {
	publishingYear = year;
}

void VideoFile::setNation(string nat) {
	// CONTROLLO SULLA LUNGHEZZA STRINGA QUI !!!
	nation = nat;
}
