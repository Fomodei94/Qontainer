#ifndef TVSERIE_H
#define TVSERIE_H

#include "VideoFile.h"

class TvSerie: public VideoFile {
	private:
		int seasons;
		bool finished;
		
	public:
		//CONSTRUCTOR:
		TvSerie(string tit,
				string gen,
				string nat,
				int year,
				int seas,
				bool fin)
		
		//GETTERS:
		int getSeasons() const;
		bool isFinished() const;
		
		//SETTERS:
		void setSeasons(int seas);
		void setFinished(bool fin);
};

#endif
