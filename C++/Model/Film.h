#ifndef FILM_H
#define FILM_H

#include "VideoFile.h"

class Film: public VideoFile {
	private:
		string director;
		int lenght;
	
	public:
		//GETTERS:
		string getDirector() const;
		int getLenght() const;
		
		//SETTERS:
		void setDirector(string dir);
		void setLenght(int len);
	
};

#endif
