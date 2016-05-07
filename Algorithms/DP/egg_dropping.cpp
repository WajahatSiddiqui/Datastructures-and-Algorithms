// Egg Dropping
// Given N floors and M eggs find the minimum number of attempts
// to drop M eggs so that it breaks from top floor
#include <iostream>
#include <climits>
using namespace std;

void print(int **T, int N, int M) {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cout << T[i][j] << " ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int max(int a, int b) {
	return a > b ? a : b;
}

void getMinAttempts(int N, int M) {
	int **T = new int*[M+1];
	for (int i = 0; i <= M; i++) {
		T[i] = new int[N+1];
	}

	for (int i = 0; i <= M; i++) {
		T[i][0] = 0;
	}

	for (int i = 0; i <= N; i++) {
		T[0][i] = 0;
	}

	// we always need one attempt if
	// we have only one egg
	for (int i = 1; i <= N; i++) {
		T[1][i] = i;
	}

	int min = INT_MAX;
	for (int i = 2; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (i > j) {
				T[i][j] = T[i-1][j];
			} else {
				for (int k = 1; k <= j; k++) {
					T[i][j] = 1 + max(T[i-1][k-1], T[i][j-k]);
					//cout <<" k = " << k << " T[i][j] = "<< T[i][j]<<endl;
					if (T[i][j] < min) min = T[i][j];
				}
				T[i][j] = min;
				min = INT_MAX;
			}
		}		
	}
    print(T, N, M);
	cout <<"Min No. of Attempts required = " << T[M][N] << endl;
	for (int i = 0; i <= M; i++)
		delete [] T[i];
	delete [] T;
}

int main() {
	int M = 2; // eggs
	int N = 6; // floors

	getMinAttempts(N, M);

	return 0;
} 