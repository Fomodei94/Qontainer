#include "VideoFile"

class SportMatch: public VideoFile {
	private:
		string championship;
		string homeTeam;
		string guestTeam;
	
	public:
		//GETTERS:
		string getChampionship();
		string getHomeTeam();
		string getGuestTeam();
		
		//SETTERS:
		void setChampionship();
		void setHomeTeam();
		void setGuestTeam();
};
