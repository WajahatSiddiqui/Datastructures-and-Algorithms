// Given an amount as N Dollars and K bills find in how many ways the dollar can be made
#include <iostream>
using namespace std;

void print(unsigned long **A, int N, int K) {
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

unsigned long getNoOfWays(int N, int K) {
	unsigned long solution = 0;
	unsigned long **T = new unsigned long*[K+1];
	for (int i = 0; i <= K; i++) {
		T[i] = new unsigned long[N+1];
	}

	for (int i = 0; i <= N; i++)
		T[0][i] = 0;

	for (int i = 1; i <= K; i++) {
		T[i][0] = 1;
	}

	for (int k = 1; k <= K; k++) {
		for (int i = 1; i <= N; i++) {
			if (i >= k) {
				T[k][i] = (T[k][i-k] + T[k-1][i]);
			} else
				T[k][i] = T[k-1][i];
		}
	}

	print(T, N, K);

	solution = T[K][N];

	// free T
	for (int i = 0; i <= K; i++)
		delete [] T[i];
	delete [] T;
	return solution;
}

int main() {
	int T = 1, N = 5, K = 3;
	//cin>>T;
	while (T--) {
		//cin>>N>>K;
		cout<<getNoOfWays(N, K)<<endl;
	}

	return 0;
}