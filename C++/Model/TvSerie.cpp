#include "TvSerie.h"

TvSerie::TvSerie(string tit, string gen, string nat, int year, int seas, bool fin) : VideoFile(tit, gen, nat, year), seasons(seas), finished(fin) {
	// CONTROLLI QUI !!!
}

// GETTERS:

int TvSerie::getSeasons() const { return seasons; }

bool TvSerie::isFinished() const { return finished; }

// SETTERS:

void TvSerie::setSeasons(int seas) {
	seasons = seas;
}

void TvSerie::setFinished(bool fin) {
	finished = fin;
}

// PUBLIC METHODS:

string TvSerie::printTvSerieStatus() const {
	if(this->isFinished()) return "Ended";
	else return "In Progress";
}
