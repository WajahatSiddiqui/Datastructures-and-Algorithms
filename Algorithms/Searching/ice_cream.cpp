// https://www.hackerrank.com/challenges/icecream-parlor
#include <iostream>
#include <cstdio>
#define MAP_SIZE 10000
#define KEY_NOT_FOUND -1
using namespace std;

/**
 * Find the indexes of two costs such that
 * ci + cj = M
 * T(n) = O(n^2)
 */
void findIndices(int C[], int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (C[i] + C[j] == M)
				cout<<i+1<<" "<<j+1<<endl;
		}
	}
}

int binary_search_iterative(int A[], int iMin, int iMax, int key) {
    // loop from iMin to iMax
    while (iMin <= iMax) {
        int iMid = (iMin + (iMax-iMin)/2);
        //cout<<"iMin = "<<iMin<<" iMax = "<<iMax<<" iMid = "<<iMid<<endl;
        // Key found in iMid itself!
        if (key == A[iMid])
            return iMid;
        // set the max index to lower subpart
        else if (key < A[iMid])
            iMax = iMid-1;
        else
        // set the min index to upper subpart
            iMin = iMid+1;
    }
    // result not found
    return KEY_NOT_FOUND;
}

void findIndicesEfficient(int C[], int N, int M) {
	int map[MAP_SIZE] = {0};
	int diff = 0;
	for (int i = 0; i < N; i++) {
		diff = M - C[i];
		if (diff >= 0 && map[diff] == 1) {
			cout<<binary_search_iterative(C, 0, N, diff)+1<<" "<<i+1<<endl;
		}
		map[C[i]] = 1;
	}
}

int main() {
	int T, M, N;
	freopen("ice_cream.txt", "r", stdin);
	cin>>T;
	int *C; // cost
	while (T--) {
		cin>>M>>N;
		C = new int[N];
		for (int i = 0; i < N; i++)
			cin>>C[i];
		findIndicesEfficient(C, N, M);

		delete [] C;
		C = NULL;
	}
	return 0;
}