#include "VideoFile.h"

class Film: public VideoFile {
	private:
		string director;
		int lenght;
	
	public:
		//GETTERS:
		string getDirector();
		int getLenght();
		
		//SETTERS:
		void setDirector(string dir);
		void setLenght(int len);
	
};
