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
		void resize(int new_size);
		
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
			if(!isFull()) {
			collection[obj_count] = new_element;
			obj_count++;
		}
		
		//void remove(any_type t);
		
};


#endif
