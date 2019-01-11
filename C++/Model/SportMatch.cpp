#include "SportMatch.h"

SportMatch::SportMatch(string tit, string gen, string nat, int year,
						string champ, string homeT, string guestT) : VideoFile(tit,gen,nat,year), championship(champ), homeTeam(homeT), guestTeam(guestT) {
		// CONTROLLI VALORI COSTRUTTORE QUI !!!	
}

// GETTERS:
string SportMatch::getChampionship() const {
	return championship;
}

string SportMatch::getHomeTeam() const {
	return homeTeam;
}

string SportMatch::getGuestTeam() const {
	return guestTeam;
}

// SETTERS:		CONTROLLI STRINGHE QUI !!!
void SportMatch::setChampionship(string champ) {
	championship = champ;
}

void SportMatch::setHomeTeam(string homeT) {
	homeTeam = homeT;
}

void SportMatch::setGuestTeam(string guestT) {
	guestTeam = guestT;
}
