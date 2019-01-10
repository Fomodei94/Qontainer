#ifndef SPORTMATCH_H
#define SPORTMATCH_H

#include "VideoFile"

class SportMatch: public VideoFile {
	private:
		string championship;
		string homeTeam;
		string guestTeam;
	
	public:
		//GETTERS:
		string getChampionship() const;
		string getHomeTeam() const;
		string getGuestTeam() const;
		
		//SETTERS:
		void setChampionship();
		void setHomeTeam();
		void setGuestTeam();
};

#endif
