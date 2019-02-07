#ifndef MOVIE_H
#define MOVIE_H

#include "VideoFile.h"

class Movie: public VideoFile {
	private:
		string director;
		int lenght;
	
	public:

		//CONSTRUCTORS:
		Movie(string tit="Unknown",
			string gen="Unknown",
			string nat="Unknown",
			int year=2000,
			string dir="Unknown",
			int lenght=0);

		//GETTERS:
		string getDirector() const;
		int getLenght() const;
		
		//SETTERS:
		void setDirector(string dir);
		void setLenght(int len);
	
};

#endif
