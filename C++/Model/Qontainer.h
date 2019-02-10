#ifndef QONTAINER_H
#define QONTAINER_H

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
			for(int i=0; i<arraySize; ++i) {
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
		
		bool pushBack(any_type new_element) {
			if(isFull()) resize(arraySize + 2);
			
			if(!isFull()){
				collection[obj_count] = new_element;
				obj_count++;
				return true;
			}
			
			else return false; // Insertion Failed.
		}
		
		void remove(const any_type& t) {	// Removes items of type t.
			
		}
		
};


#endif
