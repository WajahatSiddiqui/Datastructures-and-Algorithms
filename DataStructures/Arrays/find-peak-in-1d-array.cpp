/**
 * Find the peak element in 1d array
 * A peak element is the one which is greater
 * than its predessor and successor
 */
#include <iostream>
using namespace std;

/**
 * Bruteforce find till the condition satisfies
 * A[i-1] <= A[i] >= A[i+1]
 * T(n) = O(n)
 */ 
int findPeak(int A[], int size) {
	for (int i = 0; i < size; i++) {
		if (A[i] >= A[i+1]
			&& i > 0 && A[i] >= A[i-1]) return i;
	}
}

/**
 * Divide the problem into two halves
 * Based on mid position find if it falls in left of right half
 * T(n) = T(n/2) + c
 * T(n) ~ O(logn)
 */
int findPeakEfficient(int A[], int left, int right) {
	int mid = left + (right - left)/2;
	if (A[mid] >= A[mid+1]
		&& mid > 0 && A[mid] >= A[mid-1]) return mid;
	else if (mid > 0 && A[mid-1] > A[mid]) return findPeakEfficient(A, left, mid-1);
	else if (A[mid] < A[mid+1]) return findPeakEfficient(A, mid+1, right);
}

int main() {
	int A[] = {1, 2, 6, 5, 3, 7, 4};
	int size = sizeof(A)/sizeof(A[0]);
	cout<<"peak : "<<findPeak(A, size)<<endl;
	cout<<"peak efficient : "<<findPeakEfficient(A, 0, size-1);
	return 0;
}