#include <iostream>
using namespace std;

#ifndef __HEAP__
#define __HEAP__

class Heap {
private:
	int *m_arr;
	int m_capacity; // max size of the heap
	int m_size; // current number of elements in heap
	bool m_isMinHeap; // true if min heap need to be constructed
public:
	Heap(int capacity, bool isMinHeap = true) : m_capacity(capacity)
	, m_size(0)
	, m_isMinHeap(isMinHeap) {
		m_arr = new int[m_capacity];
	}

	Heap(int A[], int n, int isMinHeap) : m_capacity(n)
	 , m_size(n)
	 , m_isMinHeap(isMinHeap) {
		// Fixme: as we are deleting the array in destructor
		// creating memory 
		m_arr = new int[n];
		for (int i = 0; i < n; i++) m_arr[i] = A[i];
		if (m_isMinHeap) {
			minHeapify(0);
		} else {
			maxHeapify(0);
		}
	}

	~Heap() {
		delete [] m_arr;
	}

	// Utilities
	int parent(int i) { return (i - 1)/2;}
	int leftChild(int i) { return 2*i + 1; }
	int rightChild(int i) { return 2*i + 2; }
	bool isEmpty() { return m_size == 0; }
	bool isFull() { return m_size == m_capacity; }
	int getIndex(int key) {
		if (isEmpty()) return -1;
		for (int i = 0; i < m_size; i++)
			if (m_arr[i] == key) return i;
		return -1;
	}
	void decreaseKey(int i, int new_val);
	void increaseKey(int i, int new_val);
	int extractMin();
	int extractMax();

	// Operations
	void insertKey(int key);
	void deleteKey(int key);
	void deleteMin();
	void deleteMax();

	void maxHeapify(int i);
	void minHeapify(int i);

	int getMinKey();
	int getMaxKey();

	void printArray() {
		for (int i = 0; i < m_size; i++) {
			cout<<m_arr[i]<<" ";
		}
		cout<<endl;
	}

};
#endif //__HEAP__