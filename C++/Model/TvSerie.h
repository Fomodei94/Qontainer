#ifndef TVSERIE_H
#define TVSERIE_H

#include "VideoFile.h"

class TvSerie: public VideoFile {
	private:
		int seasons;
		bool finished;
		
	public:
		//CONSTRUCTOR:
		TvSerie(string tit="Unknown",
				string gen="Unknown",
				string nat="Unknown",
				int year=2000,
				int seas=1,
				bool fin=true);
		
		//GETTERS:
		int getSeasons() const;
		bool isFinished() const;
		
		//SETTERS:
		void setSeasons(int seas);
		void setFinished(bool fin);
		
		// PUBLIC METHODS:
		string printTvSerieStatus() const;
};

#endif
