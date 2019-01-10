#include "VideoFile.h"

// CONSTRUCTORS
VideoFile::VideoFile(string tit, string gen, string nat, int year) : title(tit), genre(gen), nation(nat), publishingYear(year) {
	// CONTROLLI DI CONSISTENZA VALORI QUI !!!
}



//  GETTERS:

string VideoFile::getTitle() const {
	return title;
}

string VideoFile::getGenre() const {
	return genre;
}

string VideoFile::getNation() const {
	return nation;
}

int VideoFile::getPublishingYear() const {
	return publishingYear;
}

//  SETTERS:

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
