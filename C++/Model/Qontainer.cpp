#include "Qontainer.h"

Qontainer::Qontainer(int s) : size(s) {
	collection = new any_type[s];
}

int Qontainer::getSize() const {
	return size;
}

void Qontainer::pushBack(any_type t) {
	// Trovare ultimo elemento effettivamente valido
	// e inserirci in coda nuovo elemento !!!
}
