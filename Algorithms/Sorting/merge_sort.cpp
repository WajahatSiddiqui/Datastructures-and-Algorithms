
#include<iostream>
using namespace std;

void merge_sort(int A[], int low, int high);
void merge(int A[], int low, int mid, int high);

int main() {
	int A[] = {5, 6, 8, 1, -1, 0, 11, 100, -5, 0, 1, 0, 6, 1, 2, 3, 5, 10000};
	int size = sizeof(A)/sizeof(int);
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	merge_sort(A, 0, size-1);
	cout<<"\nmerge Sorted Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}

// low represents starting index
// high represents size-1, ending index
void merge_sort(int A[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high)/2; // Divide
    merge_sort(A, low, mid); //Conquer
    merge_sort(A, mid+1, high);
    merge(A, low, mid, high); //Combine
}

void merge(int A[], int low, int mid, int high) {
    // Initialize
    int B[100], i, j, k, l, start;
    start = low;
    i = low;
    k = mid+1;
    j = high;
    l = i;

    // Form B Array
    while (i <= mid && k <= j) {
        if (A[i] <= A[k])
            B[l++] = A[i++];
        else
            B[l++] = A[k++];
    }

    // Boundary is crossed
    // copy the left over
    if (i > mid) {
        while (k <= j)
            B[l++] = A[k++];
    } else if (k > j) {
        while (i <= mid)
            B[l++] = A[i++];
    }

    // Copy B into A
    for (l = start; l <= j; l++) {
        A[l] = B[l];
    }
}
