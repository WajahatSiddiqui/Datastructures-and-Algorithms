#include "Heap.h"
#include <limits.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * Inserts a key into the heap
 * Algorithm:
 * 1) Add the key at the end
 * 2) Reduce the capacity by 1
 * 3) Fix the heap property if it is violated
 * T(n) = O(logn)
 */
void Heap::insertKey(int key) {
	if (isFull()) {
		cout<<"Heap is full !!!\n";
		return;
	}	
	m_size++;
	int i = m_size - 1;
	m_arr[i] = key;
	if (m_isMinHeap) {
		while (i != 0 && m_arr[parent(i)] > m_arr[i]) {
			swap(&m_arr[parent(i)], &m_arr[i]);
			i = parent(i);
		}
	} else {
		while (i != 0 && m_arr[parent(i)] < m_arr[i]) {
			swap(&m_arr[parent(i)], &m_arr[i]);
			i = parent(i);
		}
	}

}

/**
 * Decreases the key of index i with new value
 * fix the heap property if it is voilated
 * T(n) = O(logn)
 */
void Heap::decreaseKey(int i, int new_val) {
	m_arr[i] = new_val;
	while (i != 0 && m_arr[parent(i)] > m_arr[i]) {
		swap(&m_arr[parent(i)], &m_arr[i]);
		i = parent(i);
	}
}

/**
 * Increases the key of index i with new value
 * fix the heap property if it is violated
 * T(n) = O(logn)
 */
void Heap::increaseKey(int i, int new_val) {
	m_arr[i] = new_val;
	while (i != 0 && m_arr[parent(i)] < m_arr[i]) {
		swap(&m_arr[parent(i)], &m_arr[i]);
		i = parent(i);
	}
}

/**
 * Extracts the minimum value from the root of the heap
 * T(n) = O(logn)
 */
int Heap::extractMin() {
	if (m_size <= 0) return INT_MAX;
	if (m_size == 1) return m_arr[--m_size];
	
	// store the min value and remove it from heap
	int root = m_arr[0];
	m_arr[0] = m_arr[m_size-1];
	m_size--;
	minHeapify(0);
	return root;
}

/**
 * Extracts the maximum value from the root of the heap
 * T(n) = O(logn)
 */
int Heap::extractMax() {
	if (m_size <= 0) return INT_MIN;
	if (m_size == 1) return m_arr[--m_size];

	// store the maximum value and remove it from heap
	int root = m_arr[0];
	m_arr[0] = m_arr[m_size-1];
	m_size--;
	maxHeapify(0);
	return root;
}

/**
 * Deletes a key from heap
 */
void Heap::deleteKey(int key) {
	if (isEmpty()) {
		cout<<"Heap is empty\n";
		return;
	}
	int i = getIndex(key);
	if (m_isMinHeap) {
		decreaseKey(i, INT_MIN);
		extractMin();	
	} else {
		increaseKey(i, INT_MAX);
		extractMax();
	}	
}

/**
 *
 */
void Heap::minHeapify(int i) {
	if (!m_isMinHeap) {
		cout<<"Error minHeapify called on max heap....\n";
		return;
	}
	if (isEmpty()) {
		cout<<"Heap is empty\n";
		return;
	}

	int min = i;
	int l = leftChild(i), r = rightChild(i);
	if (l < m_size && m_arr[l] < m_arr[i]) min = l;
	if (r < m_size && m_arr[r] < m_arr[min]) min = r;
	if (min != i) {
		swap(&m_arr[i], &m_arr[min]);
		minHeapify(min);
	}
}

/**
 *
 */
void Heap::maxHeapify(int i) {
	if (m_isMinHeap) {
		cout<<"Error maxHeapify called on min heap...\n";
		return;
	}
	if (isEmpty()) {
	 cout<<"Heap is empty\n";
	 return;
	}

	int max = i;
	int l = leftChild(i), r = rightChild(i);
	if (l < m_size && m_arr[l] > m_arr[i]) max = l;
	if (r < m_size && m_arr[r] > m_arr[max]) max = r;
	if (max != i) {
	 swap(&m_arr[i], &m_arr[max]);
     maxHeapify(max);
    }
}

/**
 * Gets the top most element from the min heap
 */
int Heap::getMinKey() {
	if (!m_isMinHeap) {
		cout<<"Error min key called on max heap...\n";
		return -1;
	}
	if (isEmpty()) {
		cout<<"Heap is empty\n";
		return -1;
	}
	return m_arr[0];
}

/**
 * Gets the top most element from the max heap
 */
int Heap::getMaxKey() {
	if (m_isMinHeap) {
		cout<<"Error max key called on min heap...\n";
		return -1;
	}
	if (isEmpty()) {
		cout<<"Heap is empty\n";
		return -1;
	}
	return m_arr[0];
}