#include "../Qontainer.h"
#include "../VideoFile.h"
#include <iostream>

int main() {
	Qontainer<VideoFile> *test;
	VideoFile 	*video1, *video2, *video3;
	
	test = new Qontainer<VideoFile>(1);
	video1 = new VideoFile("Test1", "Horror", "Poland", 2018);
	video2 = new VideoFile("Test2", "Comedy", "Uruguay", 2009);
	video3 = new VideoFile("Test3", "Sci-Fi", "Italy", 2016);
	
	
	std::cout<<"isEmpty: "<<test->isEmpty()<<"  isFull: "<<test->isFull()<<std::endl;
	std::cout<<"Container size:  "<<test->getSize()<<"   Object Count:  "<<test->getObjCount()<<std::endl;
	test->pushBack(*video1);
	
	std::cout<<"After 1st insertion -->  ";
	std::cout<<"isEmpty: "<<test->isEmpty()<<"  isFull: "<<test->isFull()<<std::endl;
	std::cout<<"Container size:  "<<test->getSize()<<"   Object Count:  "<<test->getObjCount()<<std::endl;
	test->pushBack(*video2);
	
	std::cout<<"After 2nd insertion -->  ";
	std::cout<<"isEmpty: "<<test->isEmpty()<<"  isFull: "<<test->isFull()<<std::endl;
	std::cout<<"Container size:  "<<test->getSize()<<"   Object Count:  "<<test->getObjCount()<<std::endl;
	
	/*
	std::cout<<"isEmpty: "<<(*test).isEmpty()<<"  isFull: "<<(*test).isFull()<<std::endl;
	std::cout<<"Container size:  "<<(*test).getSize()<<"   Object Count:  "<<(*test).getObjCount()<<std::endl;
	(*test).pushBack(*video1);
	*/
	 
	/*
	std::cout<<"After 1st insertion -->  ";
	std::cout<<"isEmpty: "<<test.isEmpty()<<"  isFull: "<<test.isFull()<<std::endl;
	std::cout<<"Container size:  "<<test.getSize()<<"   Object Count:  "<<test.getObjCount()<<std::endl;
	test.pushBack(video2);
	std::cout<<"After 2nd insertion -->  ";
	std::cout<<"isEmpty: "<<test.isEmpty()<<"  isFull: "<<test.isFull()<<std::endl;
	std::cout<<"Container size:  "<<test.getSize()<<"   Object Count:  "<<test.getObjCount()<<std::endl;
	test.pushBack(video3);
	std::cout<<"After 3rd insertion -->  ";
	std::cout<<"isEmpty: "<<test.isEmpty()<<"  isFull: "<<test.isFull()<<std::endl;
	std::cout<<"Container size:  "<<test.getSize()<<"   Object Count:  "<<test.getObjCount()<<std::endl;
	*/
	
	std::cout<<std::endl<<"Qontainer Elements content: "<<std::endl;
	
	for( auto it= test->begin(); it<test->end(); ++it ) {
		std::cout<<" element title:  "<<(*it).getTitle()<<std::endl;
		std::cout<<" element genre:  "<<(*it).getGenre()<<std::endl;
		std::cout<<" element nation:  "<<(*it).getNation()<<std::endl;
		std::cout<<" element year:  "<<(*it).getPublishingYear()<<std::endl;
	}
	
	//std::cout<<"1st element title:  "<<(*test)[0].getTitle()<<std::endl;
	//std::cout<<"1st element genre:  "<<(*test)[0].getGenre()<<std::endl;
	//std::cout<<"1st element year:  "<<(*test)[0].getPublishingYear()<<std::endl;
	/*
	std::cout<<"2nd element title:  "<<test[1]->getTitle()<<std::endl;
	std::cout<<"2nd element year:  "<<test[1]->getPublishingYear()<<std::endl;
	std::cout<<"2nd element nation:  "<<test[1]->getNation()<<std::endl;
	
	std::cout<<"3rd element title:  "<<test[2]->getTitle()<<std::endl;
	std::cout<<"3rd element nation:  "<<test[2]->getNation()<<std::endl;
	std::cout<<"3rd element genre:  "<<test[2]->getGenre()<<std::endl;
	*/
		/*
		string getGenre() const;
		int getPublishingYear() const;
		string getNation() const;
		*/
}
