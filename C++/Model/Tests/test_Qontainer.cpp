#include "../Qontainer.h"
#include "../VideoFile.h"
#include <iostream>

int main() {
	Qontainer<VideoFile*> *myQontainer;
	VideoFile 	*video1, *video2, *video3;
	
	myQontainer = new Qontainer<VideoFile*>(5);
	video1 = new VideoFile("Test1", "Horror", "Poland", 2018);
	video2 = new VideoFile("Test2", "Comedy", "Uruguay", 2009);
	video3 = new VideoFile("Test3", "Sci-Fi", "Italy", 2016);
	
	std::cout<<"isEmpty: "<<myQontainer->isEmpty()<<"  isFull: "<<myQontainer->isFull()<<std::endl;
	std::cout<<"Container size:  "<<myQontainer->getSize()<<"   Object Count:  "<<myQontainer->getObjCount()<<std::endl;
	myQontainer->pushBack(video1);
	/*
	std::cout<<"After 1st insertion -->  ";
	std::cout<<"isEmpty: "<<myQontainer.isEmpty()<<"  isFull: "<<myQontainer.isFull()<<std::endl;
	std::cout<<"Container size:  "<<myQontainer.getSize()<<"   Object Count:  "<<myQontainer.getObjCount()<<std::endl;
	myQontainer.pushBack(video2);
	std::cout<<"After 2nd insertion -->  ";
	std::cout<<"isEmpty: "<<myQontainer.isEmpty()<<"  isFull: "<<myQontainer.isFull()<<std::endl;
	std::cout<<"Container size:  "<<myQontainer.getSize()<<"   Object Count:  "<<myQontainer.getObjCount()<<std::endl;
	myQontainer.pushBack(video3);
	std::cout<<"After 3rd insertion -->  ";
	std::cout<<"isEmpty: "<<myQontainer.isEmpty()<<"  isFull: "<<myQontainer.isFull()<<std::endl;
	std::cout<<"Container size:  "<<myQontainer.getSize()<<"   Object Count:  "<<myQontainer.getObjCount()<<std::endl;
	*/
	
	std::cout<<"1st element title:  "<<myQontainer[0]->getTitle()<<std::endl;
	std::cout<<"1st element genre:  "<<myQontainer[0]->getGenre()<<std::endl;
	std::cout<<"1st element year:  "<<myQontainer[0]->getPublishingYear()<<std::endl;
	/*
	std::cout<<"2nd element title:  "<<myQontainer[1]->getTitle()<<std::endl;
	std::cout<<"2nd element year:  "<<myQontainer[1]->getPublishingYear()<<std::endl;
	std::cout<<"2nd element nation:  "<<myQontainer[1]->getNation()<<std::endl;
	
	std::cout<<"3rd element title:  "<<myQontainer[2]->getTitle()<<std::endl;
	std::cout<<"3rd element nation:  "<<myQontainer[2]->getNation()<<std::endl;
	std::cout<<"3rd element genre:  "<<myQontainer[2]->getGenre()<<std::endl;
	*/
		/*
		string getGenre() const;
		int getPublishingYear() const;
		string getNation() const;
		*/
}
