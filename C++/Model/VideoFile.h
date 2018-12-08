#include <String> 

class VideoFile {
	
	private:
		string title;
		string genre;
		Date publishingDate;
		string nation;
		
		class Date {
			private:
				int day;
				int month;
				int year;
			public:
				//GETTERS:
				int getDay();
				int getMonth();
				int getYear();
				//SETTERS:
				void setDay(int d);
				void setMonth(int m);
				void setYear(int y);
				//CONSISTENCE CHECK:
				bool isDateCorrect(int d, int m, int y);
		};
		
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
