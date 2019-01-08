#ifndef TVSERIE_H
#define TVSERIE_H

#include "VideoFile.h"

class TvSerie: public VideoFile {
	private:
		int seasons;
		bool finished;
		
	public:
		//CONSTRUCTOR:
		TvSerie()
		
		//GETTERS:
		int getSeasons();
		bool isFinished();
		
		//SETTERS:
		void setSeasons(int seas);
		void setFinished(bool fin);
};

#endif
