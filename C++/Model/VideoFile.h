#include <String> 

class VideoFile {
	
	private:
		string title;
		string genre;
		Date publishingDate;
		string nation;
		
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
