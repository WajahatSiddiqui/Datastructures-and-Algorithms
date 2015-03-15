#include<iostream>
using namespace std;

void insertion_sort(int A[], int n);

int main() {
	int A[] = {5, 6, 8, 1, -1, 0};
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

void insertion_sort(int A[], int size) {
	int temp = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (A[j] < A[i]) {
				temp = A[j];
				A[j] = A[i];
				A[i] = temp;
			}
		}
	}
}
