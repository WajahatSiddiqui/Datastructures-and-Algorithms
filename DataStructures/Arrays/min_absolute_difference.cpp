#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

/**
 * Implements O(n) solution for printing 
 * Absolute difference
 */
void printAbsoluteDifference(vector<int> &A) {
	sort(A.begin(), A.end());
	int min = INT_MAX;
	for (int i = A.size()-1; i > 0; i--) {
		if (A[i] - A[i-1] < min) min = A[i] - A[i-1];
	}
	for (int i = 1; i < A.size(); i++) {
		if (A[i] - A[i-1] == min) {
			cout<<A[i-1]<<" "<<A[i]<<" ";
		}
	}
}

int main() {
	vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);

	printAbsoluteDifference(v);
}