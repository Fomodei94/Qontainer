#include "Film.h"

Film::Film(string tit, string gen, string nat, int year, string dir, int len) : VideoFile(tit,gen,nat,year), director(dir), lenght(len) {
	// CONTROLLI VALORI QUI !!!
}

// Getters:
string Film::getDirector() const {
	return director;
}

int Film::getLenght() const {
	return lenght;
}

// Setters:
void Film::setDirector(string dir) {
	director = dir;
}

void Film::setLenght(int len) {
	lenght = len;
}
