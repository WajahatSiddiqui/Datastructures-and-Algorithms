#include <iostream>
#include <math.h>
using namespace std;

#ifndef __HEAP__
#define __HEAP__

template class<T>
class Heap<T> {
private:
	T *m_arr;
	int m_capacity; // max size of the heap
	int m_size; // current number of elements in heap
public:
	Heap(int capacity) m_capacity(capacity) {
		m_arr = new T[m_capacity];
	}

	~Heap() {
		delete [] m_arr;
	}

	// Utilities
	int parent(int i) { return floor(i/2);}
	int leftChild(int i) { return 2*i; }
	int rightChild(int i) { return 2*i + 1; }

	// Operations
	void insert(T key);
	void deleteKey(T key);

	void maxHeapify(int i);
	void minHeapify(int i);

	T getMinKey();
	T getMaxKey();

};
#endif //__HEAP__