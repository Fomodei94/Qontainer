#ifndef ANIME_H
#define ANIME_H

#include "VideoFile.h"

class Anime: public VideoFile {
	private:
		int episodes;
		bool finished;
		
	public:
		//GETTERS:
		int getEpisodes();
		bool isFinished();
		
		//SETTERS:
		void setEpisodes(int ep);
		void setFinished(bool fin);
};

#endif
