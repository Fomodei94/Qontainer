#include "Qontainer.h"

Qontainer::Qontainer(int s) : collection(new any_type[s]), arraySize(s), obj_count(0) {

}

Qontainer::~Qontainer() {
	// Distruzione profonda intero array !!!
}

bool isEmpty() const {
	if(obj_count) return false;
	else return true;
}

bool isFull() const {
	if(arraySize == obj_count) return true;
	else return false;
}

int Qontainer::getSize() const {
	return arraySize;
}

void Qontainer::pushBack(any_type t) {
	// Trovare ultimo elemento effettivamente valido
	// e inserirci in coda nuovo elemento !!!
}
