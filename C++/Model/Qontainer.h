#ifndef QONTAINER_H
#define QONTAINER_H

#include "VideoFile.h"
#include "Movie.h"
#include "Anime.h"
#include "TvSerie.h"
#include "SportMatch.h"

template <class any_type>

class Qontainer {
	private:

		// Private data fields:
		any_type* collection;
		unsigned int arraySize;
		unsigned int obj_count;

		// Private Methods:
		void resize(int new_size) {
			any_type* new_array;
			new_array = new any_type[new_size];
			for(unsigned int i=0; i<arraySize; ++i) {
				new_array[i] = collection[i];
			}
			delete[] collection;
			collection = new_array;
			arraySize = new_size;
		}

		void Shift(int index) {
			any_type* it = collection + index;
			for(; it<arraySize-1; ++it) {
				*it = *(it+1);
			}
		}

	public:
		// Constructors:
		Qontainer(unsigned int s=2) : collection(new any_type[s]), arraySize(s), obj_count(0) {

		}

		// Destructor:
		~Qontainer() {
			delete[] collection;
		}

		// Getters:
		int getSize() const {
			return arraySize;
		}

		int getObjCount() const {
			return obj_count;
		}

		// Iterator:
		typedef any_type* iterator;

		iterator begin() {
			return collection;
		}

		iterator end() {
			return collection + obj_count;
		}

		// Operators:
		any_type& operator[] (int i) {
			if(i>=0 && i<obj_count) {
				return collection[i];
			}
			else throw("Out of bound element request");
		}

		Qontainer& operator->() {
			return (*this);
		}

		// Public Methods:

		bool isEmpty() const {
			if(obj_count) return false;
			else return true;
		}

		bool isFull() const {
			if(arraySize == obj_count) return true;
			else return false;
		}

		bool pushBack(any_type *new_element) {
			if(isFull()) resize(arraySize + 2);

			if(!isFull()){
				collection[obj_count] = (*new_element);
				obj_count++;
				return true;
			}

			else return false; // Insertion Failed.
		}
        
        // Search Methods:
        
        int searchByTitle(const QString& tit, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				if(collection[i].getTitle() == tit) {
					toReturn[ind] = i;
					ind++;
				}
			}
			return ind;
		}
		
		int searchByGenre(const QString& gen, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				if(collection[i].getGenre() == gen) {
					toReturn[ind] = i;
					ind++;
				}
			}
			return ind;
		}
		
		int searchByNation(const QString& nat, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				if(collection[i].getNation() == nat) {
					toReturn[ind] = i;
					ind++;
				}
			}
			return ind;
		}
		
		int searchByYear(const int& year, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				if(collection[i].getPublishingYear() == year) {
					toReturn[ind] = i;
					ind++;
				}
			}
			return ind;
		}
		
		int searchByDirector(const QString& dir, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				if(dynamic_cast<Movie&>(collection[i])) {
					if(collection[i].getDirector() == dir) {
						toReturn[ind] = i;
						ind++;
					}
				}
			return ind;
			}
		}
		
		int searchByEpisodes(const int& epis, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				if(dynamic_cast<Anime&> (collection[i])) {
					if(collection[i].getEpisodes() == epis) {
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
				if(dynamic_cast<TvSerie&> (collection[i])) {
					if(collection[i].getSeasons() == seas) {
						toReturn[ind] = i;
						ind++;
					}
				}
			}
			return ind;
		}
		
		int searchByChampionship(const QString& champ, int* toReturn) {
			int ind=0;
			for(unsigned int i=0; i<obj_count; ++i){
				if(dynamic_cast<SportMatch&>(collection[i])) {
					if(collection[i].getChampionship() == champ) {
						toReturn[ind] = i;
						ind++;
					}
				}
			return ind;
			}
		}
		
		// Remove Methods:
		
		void genericRemove(const int* pos, const int& numitems){
			for (unsigned int i = numitems - 1; i==0; i-- ){
				int position_to_delete = pos[i];
				delete collection[position_to_delete];
				Shift(position_to_delete);
			}
		}
		
		void removeByTitle(const QString& tit){
			int toRemove[obj_count];
			int numResults = searchByTitle(tit, toRemove);
			genericRemove(toRemove, numResults);
		}
		
		void removeByGenre(const QString& gen){
			int toRemove[obj_count];
			int numResults = searchByGenre(gen, toRemove);
			genericRemove(toRemove, numResults);
		}
		
		void removeByNation(const QString& nat){
			int toRemove[obj_count];
			int numResults = searchByNation(nat, toRemove);
			genericRemove(toRemove, numResults);
		}
				
		void removeByYear(const int& year){
			int toRemove[obj_count];
			int numResults = searchByYear(year, toRemove);
			genericRemove(toRemove, numResults);
		}

};


#endif
