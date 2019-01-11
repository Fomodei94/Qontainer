#ifndef SPORTMATCH_H
#define SPORTMATCH_H

#include "VideoFile.h"

class SportMatch: public VideoFile {
	private:
		string championship;
		string homeTeam;
		string guestTeam;
	
	public:
		// CONSTRUCTORS:
		SportMatch(string tit="Unknown",
					string gen="Unknown",
					string nat="Unknown",
					int year=2000,
					string champ="Unknown",
					string homeT="Unknown",
					string guestT="Unknown");

		//GETTERS:
		string getChampionship() const;
		string getHomeTeam() const;
		string getGuestTeam() const;
		
		//SETTERS:
		void setChampionship(string champ);
		void setHomeTeam(string homeT);
		void setGuestTeam(string guestT);
};

#endif
