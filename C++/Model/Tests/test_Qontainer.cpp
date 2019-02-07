#include "../Qontainer.h"
#include "../VideoFile.h"
#include <iostream>

int main() {
	Qontainer<VideoFile> myQontainer;
	VideoFile video1, video2, video3;
	
	std::cout<<myQontainer.isEmpty()<<"   "<<myQontainer.isFull()<<std::endl;
	myQontainer.pushBack(video1);
	std::cout<<myQontainer.isEmpty()<<"   "<<myQontainer.isFull()<<std::endl;
	myQontainer.pushBack(video2);
	std::cout<<myQontainer.isEmpty()<<"   "<<myQontainer.isFull()<<std::endl;
}
