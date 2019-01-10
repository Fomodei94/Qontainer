#include "../VideoFile.h"
#include "../TvSerie.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main() {
	
	// VideoFile Tests:
	
	cout<<"VIDEOFILE TESTS:"<<endl;
	
	VideoFile* punt = new VideoFile();
	VideoFile* video = new VideoFile("TuaMamma", "Horror", "Italia", 2018);
	
	cout<<"DEFAULT CONSTRUCTOR & GETTERS TESTS:"<<endl;
	cout<<punt->getTitle()<<endl; 
	cout<<punt->getGenre()<<endl; 
	cout<<punt->getNation()<<endl; 
	cout<<punt->getPublishingYear()<<endl<<endl;
	
	cout<<"COMPLETE CONSTRUCTOR & GETTERS TESTS:"<<endl;
	cout<<video->getTitle()<<endl;
	cout<<video->getNation()<<endl;
	cout<<video->getGenre()<<endl;
	cout<<video->getPublishingYear()<<endl<<endl;
	
	cout<<"SETTERS TESTS:"<<endl;
	video->setTitle("Vivalagnagna");
	cout<<video->getTitle()<<endl;
	video->setNation("Gnagnalandia");
	cout<<video->getNation()<<endl;
	video->setGenre("Drammatico");
	cout<<video->getGenre()<<endl;
	video->setPublishingYear(2542);
	cout<<video->getPublishingYear()<<endl;
	punt->setTitle("Ocuspocus");
	cout<<punt->getTitle()<<endl; 
	
	// TvSerie Tests:
	
	TvSerie* tv = new TvSerie("Tbbt", "comedy", "Usa", 2006, 12, false);
	
	cout<<endl<<"TVSERIE CONSTR & GETTERS TEST:"<<endl;
	cout<<tv->getSeasons()<<endl;
	cout<<tv->isFinished()<<endl;
	
}
