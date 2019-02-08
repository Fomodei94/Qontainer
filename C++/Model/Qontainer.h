#ifndef QONTAINER_H
#define QONTAINER_H

template <class any_type>

class Qontainer {
	private:
		
		// Private data fields:
		any_type* collection;
		int arraySize;
		int obj_count;
		
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
		
	public:
		// Constructors:
		Qontainer(int s=2) : collection(new any_type[s]), arraySize(s), obj_count(0) {

		}
		
		// Destructor:
		~Qontainer()=default;
		
		// Getters:
		int getSize() const {
			return arraySize;
		}
		
		int getObjCount() const {
			return obj_count;
		}
		
		//Operators:
		any_type& operator[] (int i) {
			if(i>=0 && i<obj_count) {
				return collection[i];
			}
			else throw("Out of bound element request");
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
		
		void pushBack(any_type new_element) {
			if(isFull()) resize(arraySize + 5);
			
			if(!isFull()){
				collection[obj_count] = new_element;
				obj_count++;
			}
			
			else throw("Error with element insertion!");
			
		}
		
		//void remove(any_type t);
		
};


#endif
