#include "Qontainer.h"

template <class any_type>
Qontainer::Qontainer(int s) : collection(new any_type[s]), arraySize(s), obj_count(0) {

}

template <class any_type>
Qontainer::~Qontainer() {
	// Distruzione profonda intero array !!!
}

template <class any_type>
bool isEmpty() const {
	if(obj_count) return false;
	else return true;
}

template <class any_type>
bool isFull() const {
	if(arraySize == obj_count) return true;
	else return false;
}

template <class any_type>
int Qontainer::getSize() const {
	return arraySize;
}

template <class any_type>
void Qontainer::pushBack(any_type new_element) {
	// Trovare ultimo elemento effettivamente valido
	// e inserirci in coda nuovo elemento !!!
	if(!isFull) {
		collection[obj_count] = new_element;
		obj_count++;
	}
}
