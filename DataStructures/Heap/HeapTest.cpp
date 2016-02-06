#include "Heap.h"

int main() {
	int A[] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
	int size = sizeof(A)/sizeof(A[0]);
	Heap *heap = new Heap(A, size, false);
	cout<<"Building a Min Heap with: ";
	heap->printArray();
	heap->maxHeapify(2);
	heap->printArray();

	delete heap;
	return 0;
}