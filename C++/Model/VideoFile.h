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
		
	public:
		
		// CONSTRUCTORS:
		VideoFile(string tit="Unknown",
					string gen="Unknown",
					string nat="Unknown", 
					int year=2000);
		
		// GETTERS:
		virtual string getTitle() const;
		virtual string getGenre() const;
		virtual int getPublishingYear() const;
		virtual string getNation() const;
		// SETTERS:
		virtual void setTitle(string tit);
		virtual void setGenre(string gen);
		virtual void setPublishingYear(int year);
		virtual void setNation(string nat);
		
		virtual ~VideoFile() =default;
};

#endif
