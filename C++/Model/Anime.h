#ifndef ANIME_H
#define ANIME_H

#include "VideoFile.h"

class Anime: public VideoFile {
	private:
		int episodes;
		bool finished;
		
	public:
	
		//CONSTRUCTORS:
		Anime(string tit="Unknown",
			string gen="Unknown",
			string nat="Unknown",
			year=2000,
			int epis=1,
			bool fin=true);	
		
		//GETTERS:
		int getEpisodes() const;
		bool isFinished() const;
		
		//SETTERS:
		void setEpisodes(int epis);
		void setFinished(bool fin);
		
		// PUBLIC METHODS:
		string printAnimeStatus() const;
};

#endif
