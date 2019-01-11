#include "../VideoFile.h"
#include "../TvSerie.h"
#include "../SportMatch.h"
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
	cout<<tv->getTitle()<<endl;
	cout<<tv->getGenre()<<endl;
	cout<<tv->getNation()<<endl;
	cout<<tv->getPublishingYear()<<endl;
	cout<<tv->getSeasons()<<endl;
	cout<<tv->isFinished()<<endl;
	
	// SportMatch Tests:
	
	SportMatch* sp = new SportMatch();
	SportMatch* sport = new SportMatch("PartitaFiga", "Calcio", "Italia", 2008, "Serie A", "Inter", "Milan");
	
	cout<<endl<<"SPORTMATCH DEF. CONSTR. & GETTERS TEST:"<<endl;
	cout<<sp->getTitle()<<endl;
	cout<<sp->getGenre()<<endl;
	cout<<sp->getNation()<<endl;
	cout<<sp->getPublishingYear()<<endl;
	cout<<sp->getChampionship()<<endl;
	cout<<sp->getHomeTeam()<<endl;
	cout<<sp->getGuestTeam()<<endl;
	
	cout<<endl<<"SPORTMATCH COMPLETE CONSTR. & GETTERS TEST:"<<endl;
	cout<<sport->getTitle()<<endl;
	cout<<sport->getGenre()<<endl;
	cout<<sport->getNation()<<endl;
	cout<<sport->getPublishingYear()<<endl;
	cout<<sport->getChampionship()<<endl;
	cout<<sport->getHomeTeam()<<endl;
	cout<<sport->getGuestTeam()<<endl;
	
}
