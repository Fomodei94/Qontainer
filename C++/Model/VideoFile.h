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
		// GETTERS:
		string getTitle();
		string getGenre();
		int getPublishingYear();
		string getNation();
		//SETTERS:
		void setTitle(string tit);
		void setGenre(string gen);
		void setPublishingYear(int year);
		void setNation(string nat);
};
