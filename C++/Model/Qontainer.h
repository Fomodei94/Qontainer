#ifndef QONTAINER_H
#define QONTAINER_H

#include <iostream>
#include <string>
#include <locale>
#include "VideoFile.h"
#include "Movie.h"
#include "Anime.h"
#include "TvSerie.h"
#include "SportMatch.h"

using std::string;
using std::locale;

template <class any_type>

class Qontainer {
	private:

		// Private data fields:
		any_type* collection;	// pointer to array of any_type pointers.
		unsigned int arraySize;
		unsigned int obj_count;

		// Private Methods:
		void resize(unsigned int new_size) {
			any_type* new_array;
			new_array = new any_type[new_size];
			for(unsigned int i=0; i<arraySize; ++i) {
				new_array[i] = collection[i];
			}
			delete[] collection;
			collection = new_array;
			arraySize = new_size;
		}

		void Shift(unsigned int index) {
			//any_type *it = collection + index;
			for(; index<obj_count-1; ++index) {
				collection[index] = collection[index+1];
			}
		}

	public:
		// Constructors:
		Qontainer(unsigned int s=3) : collection(new any_type[s]), arraySize(s), obj_count(0) {

		}

		// Destructor:
		~Qontainer() {
			delete[] collection;
		}

		// Getters:
		unsigned int getSize() const {
			return arraySize;
		}

		unsigned int getObjCount() const {
			return obj_count;
		}

		// Iterator:
		typedef any_type* iterator;

		iterator begin() {
			return (*collection);
		}

		iterator end() {
			return (*collection) + obj_count;
		}

		// Operators:
		any_type operator[](unsigned int i) {
			if(i>=0 && i<obj_count) {
				return collection[i];
			}
			else throw("Out of bound element request");
		}

		any_type operator->() {
			return (*collection);
		}

		// Public Methods:

		void clear() {
		        any_type* aux = nullptr;
		        delete [] collection;
		        collection = aux;
		        obj_count = 0;
		        arraySize = 0;
		    }

		bool isEmpty() const {
			if(obj_count) return false;
			else return true;
		}

		bool isFull() const {
			if(arraySize == obj_count) return true;
			else return false;
		}

		void pushBack(any_type new_element) {
			if(isFull()) resize(arraySize + 1);

			if(!isFull()){
				collection[obj_count] = new_element;
				obj_count++;
			}
		}

        // Search Methods:

    int searchByTitle(const string& tit, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; i++){
				std::locale loc;
				string titleToCheck = collection[i]->getTitle();
				string titleToLowercase;
				for(string::size_type i=0; i<titleToCheck.size(); i++) {
					titleToLowercase += tolower(titleToCheck[i], loc);
				}

				if(titleToLowercase == tit) {
					toReturn[ind] = i;
					ind++;
				}
			}
			return ind;
		}

		int searchByGenre(const string& gen, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				std::locale loc;
				string genreToCheck = collection[i]->getGenre();
				string genreToLowercase;
				for(string::size_type i=0; i<genreToCheck.size(); i++) {
					genreToLowercase += tolower(genreToCheck[i], loc);
				}

				if(genreToLowercase == gen) {
					toReturn[ind] = i;
					ind++;
				}
			}
			return ind;
		}

		int searchByNation(const string& nat, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				std::locale loc;
				string nationToCheck = collection[i]->getNation();
				string nationToLowercase;
				for(string::size_type i=0; i<nationToCheck.size(); i++) {
					nationToLowercase += tolower(nationToCheck[i], loc);
				}
				if(nationToLowercase == nat) {
					toReturn[ind] = i;
					ind++;
				}
			}
			return ind;
		}

		int searchByYear(const int& year, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				if(collection[i]->getPublishingYear() == year) {
					toReturn[ind] = i;
					ind++;
				}
			}
			return ind;
		}

		int searchByDirector(const string& dir, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				VideoFile* aux = collection[i];
				Movie* dinam = dynamic_cast<Movie*>(aux);
				if(dinam) {
					std::locale loc;
					string directorToCheck = dinam->getDirector();
					string directorToLowercase;
					for(string::size_type i=0; i<directorToCheck.size(); i++) {
						directorToLowercase += tolower(directorToCheck[i], loc);
					}
					if(directorToLowercase == dir) {
						toReturn[ind] = i;
						ind++;
					}
				}
			}
			return ind;
		}

		int searchByEpisodes(const int& epis, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				VideoFile* aux = collection[i];
				Anime* dinam = dynamic_cast<Anime*>(aux);
				if(dinam) {
					if(dinam->getEpisodes() == epis) {
						toReturn[ind] = i;
						ind++;
					}
				}
			}
			return ind;
		}

		int searchBySeasons(const int& seas, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				VideoFile* aux = collection[i];
				TvSerie* dinam = dynamic_cast<TvSerie*>(aux);
				if(dinam) {
					if(dinam->getSeasons() == seas) {
						toReturn[ind] = i;
						ind++;
					}
				}
			}
			return ind;
		}

		int searchByChampionship(const string& champ, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				VideoFile* aux = collection[i];
				SportMatch* dinam = dynamic_cast<SportMatch*>(aux);
				if(dinam) {
					std::locale loc;
					string championshipToCheck = dinam->getChampionship();
					string championshipToLowercase;
					for(string::size_type i=0; i<championshipToCheck.size(); i++) {
						championshipToLowercase += tolower(championshipToCheck[i], loc);
					}
					if(championshipToLowercase == champ) {
						toReturn[ind] = i;
						ind++;
					}
				}
			}
			return ind;
		}

		Qontainer<any_type>* returnFromPosition(int* itemsIndex, unsigned int num_elements) {
			Qontainer<any_type> *toReturn = new Qontainer<any_type>();
			for(unsigned int i = 0; i<num_elements; i++) {
				int ind = itemsIndex[i];
				toReturn->pushBack(collection[ind]);
			}
			return toReturn;
		}

		// Remove Methods:

		void genericRemove(int* toRemove, int numitems){
			for (int i = numitems - 1; i>-1; i--) {
				int position_to_delete = toRemove[i];
				delete collection[position_to_delete];
				Shift(position_to_delete);
				obj_count--;
			}
		}

		void removeByTitle(const string& tit){
			int toRemove[obj_count];
			int numResults = searchByTitle(tit, toRemove);
			genericRemove(toRemove, numResults);
		}

		void removeByGenre(const string& gen){
			int toRemove[obj_count];
			int numResults = searchByGenre(gen, toRemove);
			genericRemove(toRemove, numResults);
		}

		void removeByNation(const string& nat){
			int toRemove[obj_count];
			int numResults = searchByNation(nat, toRemove);
			genericRemove(toRemove, numResults);
		}

		void removeByYear(const int& year){
			int toRemove[obj_count];
			int numResults = searchByYear(year, toRemove);
			genericRemove(toRemove, numResults);
		}

		void removeByDirector(const string& dir){
			int toRemove[obj_count];
			int numResults = searchByDirector(dir, toRemove);
			genericRemove(toRemove, numResults);
		}

		void removeByEpisodes(const int& epis){
			int toRemove[obj_count];
			int numResults = searchByEpisodes(epis, toRemove);
			genericRemove(toRemove, numResults);
		}

		void removeBySeasons(const int& seas){
			int toRemove[obj_count];
			int numResults = searchBySeasons(seas, toRemove);
			genericRemove(toRemove, numResults);
		}

		void removeByChampionship(const string& champ){
			int toRemove[obj_count];
			int numResults = searchByChampionship(champ, toRemove);
			genericRemove(toRemove, numResults);
		}

};


#endif
