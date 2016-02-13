#include <string.h>
#include "Sorting.h"


int main() {
	int A[] = {5, 6, 8, 1, -1, 0, 11, 100, -5, 0, 1, 0, 6, 1, 2, 3, 5, 10000};
	int size = sizeof(A)/sizeof(int);
	int *B = new int[size];
	memcpy(B, A, sizeof(A));
	Sorting sorting;
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: \n";
	sorting.print_array(A, size);
	
	cout<<"Selection sort\n";
	sorting.selection_sort(A, size);
	sorting.print_array(A, size);
	memcpy(A, B, sizeof(A)); // reset the array
	
	cout<<"Bubble sort\n";
	sorting.bubble_sort(A, size);
	sorting.print_array(A, size);
	memcpy(A, B, sizeof(A));
	
	cout<<"Inserting sort\n";
	sorting.insertion_sort(A, size);
	sorting.print_array(A, size);
	memcpy(A, B, sizeof(A));

	cout<<"Merge sort\n";
	sorting.merge_sort(A, 0, size-1);
	sorting.print_array(A, size);
	memcpy(A, B, sizeof(A));

	cout<<"Quick sort\n";
	sorting.quick_sort(A, 0, size-1);
	sorting.print_array(A, size);
	memcpy(A, B, sizeof(A));

	cout<<"Shell sort\n";
	sorting.shell_sort(A, size);
	sorting.print_array(A, size);
	memcpy(A, B, sizeof(A));

	cout<<"Bucket sort\n";
	sorting.bucket_sort(A, size);
	sorting.print_array(A, size);
    memcpy(A, B, sizeof(A));

	cout<<"Counting sort\n";
	sorting.counting_sort(A, size);
	sorting.print_array(A, size);
	memcpy(A, B, sizeof(A));

	cout<<"Radix sort\n";
	sorting.radix_sort(A, size);
	sorting.print_array(A, size);
    memcpy(A, B, sizeof(A));

	cout<<"Heap sort\n";
	sorting.heap_sort(A, size);
	sorting.print_array(A, size);

    delete [] B;
	return 0;
}