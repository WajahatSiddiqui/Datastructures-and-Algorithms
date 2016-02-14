#include "Heap.h"

int main() {
	/*int A[] = {3, 1, 5, 2, 7};
	int size = sizeof(A)/sizeof(A[0]);
	cout<<"Building a Max Heap with: ";
	Heap *heap = new Heap(A, size, false);	
	heap->printArray();
	cout<<"Max key: "<<heap->getMaxKey()<<endl;
	delete heap;*/

	Heap *minHeap = new Heap(5);
	minHeap->insertKey(3);
	minHeap->insertKey(1);
	minHeap->insertKey(5);
	minHeap->insertKey(2);
	minHeap->insertKey(7);
	cout<<"Min heap built with following keys: ";
	minHeap->printArray();
	cout<<"Min key: "<<minHeap->getMinKey()<<endl;

	cout<<"Deleting key = 2\n";
	minHeap->deleteKey(2);
	minHeap->printArray();

	Heap *maxHeap = new Heap(5, false);
	maxHeap->insertKey(3);
	maxHeap->insertKey(1);
	maxHeap->insertKey(5);
	maxHeap->insertKey(2);
	maxHeap->insertKey(7);
	cout<<"Max heap built with following keys: ";
	maxHeap->printArray();
	cout<<"Max key: "<<maxHeap->getMaxKey()<<endl;

	cout<<"Deleting key = 5\n";
	maxHeap->deleteKey(5);
	maxHeap->printArray();

	delete maxHeap;
	delete minHeap;
	return 0;
}