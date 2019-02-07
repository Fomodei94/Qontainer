#ifndef QONTAINER_H
#define QONTAINER_H

template <class any_type>

class Qontainer {
	private:
		// Private data fields:
		any_type* collection[];
		int size;
		int obj_count;
		
		// Private Methods:
		void resize(int new_size);
		
		any_type[] deepCopy(any_type* a[]);
		
	public:
		// Constructors:
		Qontainer(int s=100);
		
		// Getters:
		int getSize() const;
		
		// Public Methods:
		
		bool isEmpty() const;
		
		bool isFull() const;
		
		void pushBack(any_type t);    // Tipo del parametro? 
									// Puntatore a any_type o VideoFile?
									// O riferimento costante?
		void remove(any_type t);
		
		
		
		
		
};

#endif
