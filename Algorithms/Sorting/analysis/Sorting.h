#ifndef __SORTING__
#define __SORTING__

#include <iostream>
using namespace std;

class Sorting {
public:
	void selection_sort(int A[], int size);
	void bubble_sort(int A[], int size);
	void insertion_sort(int A[], int size);
	void merge_sort(int A[], int size);
	void quick_sort(int A[], int size);
	void shell_sort(int A[], int size);
	void bucket_sort(int A[], int size);
	void counting_sort(int A[], int size);
	void radix_sort(int A[], int size);
	void heap_sort(int A[], int size);

	// Utilities
	void print_array(int A[], int size) {
		for (int i = 0; i < size; i++) cout<<A[i]<<" ";
		cout<<endl;
	}
};

#endif //__SORTING__

