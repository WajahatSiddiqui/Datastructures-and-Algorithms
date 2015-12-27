#include<iostream>
using namespace std;

// Best case: O(nlogn)
// Avg. case: O(n^2)
// Worst case: O(n^2)
void shell_sort(int A[], int size);

int main() {
	int A[] = {5, 6, 8, 1, -1, 0, 11, 100, -5, 0, 1, 0, 6, 1, 2, 3, 5, 10000};
	int size = sizeof(A)/sizeof(int);
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	shell_sort(A, size);
	cout<<"\nShell Sorted Array: \n";
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

void shell_sort(int A[], int size) {
    int i,j;
    // start with the bigger gap and reduce it gradually
    for (int gap = size/2; gap > 0; gap /= 2) {
        // Perform insertion sort within the gap
        for (i = gap; i < size; i++) {
            int key = A[i];
            // shift earlier gap sorted array until the correct location of A[i] is found
            for (j = i; j >= gap && A[j-gap] > key; j-=gap) A[j] = A[j-gap];
            // put the key into correct location
            A[j] = key;
        }
    }
}

