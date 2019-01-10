#ifndef VIDEOFILE_H
#define VIDEOFILE_H

#include <string> 
using std::string;

class VideoFile {
	
	private:
		string title,
				genre,
				nation;
		int publishingYear;
		
		// METODO PRIVATO (O PROTETTO) DI UTILITA' PER VERIFICARE LUNGH MAX STRINGHE QUI !!!
		
	public:
		
		// CONSTRUCTORS:
		VideoFile(string tit="Unknown",
					string gen="Unknown",
					string nat="Unknown", 
					int year=2000);
		
		// GETTERS:
		string getTitle() const;
		string getGenre() const;
		int getPublishingYear() const;
		string getNation() const;
		// SETTERS:
		void setTitle(string tit);
		void setGenre(string gen);
		void setPublishingYear(int year);
		void setNation(string nat);
};

#endif
