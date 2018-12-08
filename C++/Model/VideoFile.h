#include <string> 
using std::string;
using std::to_string();

class VideoFile {
	
	private:
		string title,
				genre,
				nation;
		Date publishingDate;
		
		class Date {
			private:
				int day,
					month,
					year;
			public:
				//CONSTRUCTOR:
				Date(int d, int m, int y);
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
				//PRINTING FUNCTION:
				string printDateString(int d, int m, int y);
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
