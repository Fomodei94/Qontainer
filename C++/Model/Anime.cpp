#include "Anime.h"

Anime::Anime(string tit, string gen, string nat, int year, int epis, bool fin) : VideoFile(tit,gen,nat,year), episodes(epis), finished(fin) {
	// CONTROLLI VALORI QUI !!!
}

// Getters:
int Anime::getEpisodes() const {
	return episodes;
}

bool Anime::isFinished() const {
	return finished;
}

// Setters:
void Anime::setEpisodes(int epis) {
	episodes = epis;
}

void Anime::setFinished(bool fin) {
	finished = fin;
}

// Public Methods:
string Anime::printAnimeStatus() const {
	if(this->isFinished()) return "Ended";
	else return "In Progress";
}
