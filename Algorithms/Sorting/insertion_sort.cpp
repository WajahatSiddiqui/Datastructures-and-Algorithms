#include<iostream>
using namespace std;
// Best case: O(n)
// Avg. case: O(n^2)
// Worst case: O(n^2)
// Sorts array A in increasing order
// Qualities: 
// 1) Efficient - for small data sets and other quadratic algorithms
// 2) Stable - Doesn't change the relative order
// 3) Inplace - Doesn't need additional memory sorts as it receives online
void insertion_sort(int A[], int n);
void swap(int *n1, int *n2);

int main() {
    int A[] = {5, 6, 8, 1, -1, 0, 11, 100, -5, 0, 1, 0, 6, 1, 2, 3, 5, 10000};
    int size = sizeof(A)/sizeof(int);
    cout<<"Size = "<<size<<endl;
    cout<<"Input Array: \n";
    for (int i = 0; i < size; i++) {
        cout<<A[i]<<" ";
    }
    insertion_sort(A, size);
    cout<<"\nInsertion Sorted Array: \n";
    for (int i = 0; i < size; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// Algorithm:
// 1) i = start/prev element, j = next element
// 2) A[j] < A[j] swap(A[j], A[i])
// 3) continue 1) untill all elements are sorted.
void insertion_sort(int A[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (A[j] < A[i]) {
                swap(A[j], A[i]);
            }
        }
    }
}

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
