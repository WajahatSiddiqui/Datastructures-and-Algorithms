// Longest Increasing Subsequence Length
// https://www.youtube.com/watch?v=CE2b_-XfVDk&index=5&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
#include <iostream>
#include <limits.h>
using namespace std;

inline int max(int a, int b) {
	return a > b ? a : b;
}

void print(int T[], int size) {
	for (int i = 0; i < size; i++)
		cout<<T[i]<<" ";
	cout<<endl;
}

/**
 * Handling duplicate entries as well
 * T(n) = O(n^2)
 */
int findLength(int A[], int size) {
	print(A, size);
	int *T = new int[size];
	for (int i = 0; i < size; i++)
		T[i] = 1;

	for(int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {			
			if (A[j] < A[i]) {				
				T[i] = max(T[j]+1, T[i]);
			}
		}
	}

	print(T, size);

	int m = INT_MIN;
	for (int i = 0; i < size; i++) {
		if (T[i] > m) m = T[i];
	}

	delete [] T;
	return m;
}

int main() {
	int A[] = {3, 4, 0, -1, 2, 6, 3, 3, 4, 5};
	int size = sizeof(A)/sizeof(A[0]);
	cout<<findLength(A, size)<<endl;
}