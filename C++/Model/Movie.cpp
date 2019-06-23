#include "Movie.h"

Movie::Movie(string tit, string gen, string nat, int year, string dir, int len) : VideoFile(tit,gen,nat,year), director(dir), length(len) {
	// CONTROLLI VALORI QUI !!!
}

// Getters:
string Movie::getDirector() const {
	return director;
}

int Movie::getLength() const {
	return length;
}

// Setters:
void Movie::setDirector(string dir) {
	director = dir;
}

void Movie::setLength(int len) {
	length = len;
}
