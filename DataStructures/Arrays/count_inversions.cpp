// http://www.geeksforgeeks.org/counting-inversions/
#include <iostream>
#include <set>
#include <iterator>
using namespace std;

/**
 * Count the number of inversions in the array
 * T(n) = O(n)
 */
int countInversions(int A[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (A[i] > A[j]) count++;
		}
	}
	return count;
}

int merge(int *A, int *B, int lo, int mi, int hi) {
	int count = 0, i, j, k;
	i = lo;
	j = mi;
	k = lo;

	while ((i <= mi-1) && (j <= hi)) {
		if (A[i] <= A[j])
			B[k++] = A[i++];
		else {
			B[k++] = A[j++];
			count += mi-i;
		}
	}

	while (i <= mi-1)
		B[k++] = A[i++];
	while (j <= hi)
		B[k++] = A[j++];

	for (i = lo; i <= hi; i++) {
		A[i] = B[i];
	}
	return count;
}

/**
 * Divides the list into two halves
 * based on DNC technique
 * T(n) = O(nlogn)
 */
int countInversionsDNC(int A[], int B[], int lo, int hi) {
	int mi, count = 0;
	if (hi > lo) {
		mi = (hi + lo)/2;
		count = countInversionsDNC(A, B, lo, mi);
		count +=  countInversionsDNC(A, B, mi+1, hi);
		count += merge(A, B, lo, mi+1, hi);
	}
	return count;
}

void printSet(set<int> &s) {
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); ++it) {
		cout<<*it<<" ";
	}
}

/**
 * Store the values in the set: Count the number of elements
 * greated than the given element in the set
 * Set the upper bound to the given element
 * calculate the distance between upper bound and the end of the set 
 * T(n) = O(n^2) worst
 * S(n) = O(n)
 */
int countInversionsSet(int A[], int size) {
	set<int> s;
	set<int>::iterator itup;
	int count = 0;
	for (int i = 0; i < size; i++) {
		s.insert(A[i]);
		itup = s.upper_bound(A[i]);
		count += distance(itup, s.end());
	}
	//printSet(s);
	return count;
}

int main() {
	int A[] = {2, 4, 1, 3, 5};
	int size = sizeof(A)/sizeof(A[0]);

	cout<<countInversions(A, size)<<endl;
	cout<<countInversionsSet(A, size)<<endl;
	int *B = new int[size];
	cout<<countInversionsDNC(A, B, 0, size-1);

	delete [] B;
	return 0;
}