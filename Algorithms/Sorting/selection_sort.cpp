#include<iostream>
using namespace std;

void selection_sort(int A[], int n);
void swap(int *i1, int *i2);

int main() {
	int A[] = {5, 6, 8, 1, -1, 0, 11, 100, -5, 0, 1, 0, 6, 1, 2, 3, 5, 10000};
	int size = sizeof(A)/sizeof(int);
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	selection_sort(A, size);
	cout<<"\nSelection Sorted Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}

void selection_sort(int A[], int size) {
    // minimum index for selection sort
    int min_index = 0;
    // Advance the position to the entire array
    // A[0] ... A[size -1]
    for (int i = 0; i < size; i++) {
        // Find the minimum element in the unsorted array
        // Assume mimimum index is first element (i)
        min_index = i;
        // test this minimum index against all the other
        // elements in the array
        for (int j = i+1; j < size; j++) {
            // compare left most element with current minimum
            if (A[j] < A[min_index])
                // update the minimum index
                min_index = j;

        }
        // minimum index is found, test wheather
        // this is different from current left most
        if (A[i] != A[min_index])
            // exchange with unsorted
            swap(A[i], A[min_index]);
    }
}

void swap(int *i1, int *i2) {
    int temp;
    temp = *i1;
    *i1 = *i2;
    *i2 = temp;
}
