
#include<iostream>
using namespace std;

void bubble_sort(int A[], int n);
void swap(int *i1, int *i2);

int main() {
	int A[] = {5, 6, 8, 1, -1, 0, 11, 100, -5, 0, 1, 0, 6, 1, 2, 3, 5, 10000};
	int size = sizeof(A)/sizeof(int);
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	bubble_sort(A, size);
	cout<<"\nBubble Sorted Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}

void bubble_sort(int A[], int size) {
    // compare each of the two elements (pairs)
    // exchange if there are out of order
    for (int i = 0; i < (size - 1); i++) {
        for (int j = 0; j < (size - i - 1); j++) {
            if (A[j] > A[j+1])
                swap(A[j], A[j+1]);
        }
    }
}

void swap(int *i1, int *i2) {
    int temp;
    temp = *i1;
    *i1 = *i2;
    *i2 = temp;
}
