#include "Date.h"
#include <string> 
using std::string;

class VideoFile {
	
	private:
		string title,
				genre,
				nation;
		Date publishingDate;
		
		// METODO PRIVATO (O PROTETTO) DI UTILITA' PER VERIFICARE LUNGH MAX STRINGHE QUI !!!
		
	public:
		// GETTERS:
		string getTitle();
		string getGenre();
		Date getPublishingDate();
		string getNation();
		//SETTERS:
		void setTitle(string tit);
		void setGenre(string gen);
		void setPublishingDate(Date dat);
		void setNation(string nat);
};
