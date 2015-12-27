#include<iostream>
using namespace std;

// Best case: O(nlogn)
// Avg. case: O(nlogn)
// Worst case: O(n^2)
void quick_sort(int A[], int low, int high);
int  partition(int A[], int low, int high);

int main() {
	int A[] = {5, 6, 8, 1, -1, 0, 11, 100, -5, 0, 1, 0, 6, 1, 2, 3, 5, 10000};
	int size = sizeof(A)/sizeof(int);
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	quick_sort(A, 0, size-1);
	cout<<"\nQuick Sorted Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}

void swap(int *n1, int *n2) {
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

// low represents starting index
// high represents size-1, ending index
void quick_sort(int A[], int low, int high) {
    if (low < high) {
        // Partition the array based on some pivot
        int pivot = partition(A, low, high);
        // Decompose and sort recursively
        quick_sort(A, low, pivot-1);
        quick_sort(A, pivot+1, high);
    }
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int  i = low - 1;
    for (int j = low; j <= high-1; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    return i+1;
}

