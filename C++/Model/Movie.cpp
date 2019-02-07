#include "Movie.h"

Movie::Movie(string tit, string gen, string nat, int year, string dir, int len) : VideoFile(tit,gen,nat,year), director(dir), lenght(len) {
	// CONTROLLI VALORI QUI !!!
}

// Getters:
string Movie::getDirector() const {
	return director;
}

int Movie::getLenght() const {
	return lenght;
}

// Setters:
void Movie::setDirector(string dir) {
	director = dir;
}

void Movie::setLenght(int len) {
	lenght = len;
}
