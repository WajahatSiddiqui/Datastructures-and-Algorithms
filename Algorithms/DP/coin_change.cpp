#include <iostream>
using namespace std;


void printArray(unsigned long **A, unsigned int M, unsigned int N) {
	for (unsigned int i = 0; i <= M; i++) {
		for (unsigned int j = 0; j <= N; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
/**
 * Returns the number of ways in which the coins
 * can be arranges to form the total = N
 */
unsigned long getNumberOfWays(int C[], int M, int N) {
    unsigned long solution = 0;
	unsigned long  **T = new unsigned long*[M+1];
	for (int i = 0; i <= M; i++)
		T[i] = new unsigned long[N+1];

	for (int i = 0; i <= M; i++) {
		T[i][0] = 1;
	}

	for (unsigned int i = 1; i <= M; i++) {
		for (unsigned int j = 1; j <= N; j++) {
			if (j >= C[i-1]) {
				T[i][j] = T[i-1][j] + T[i][j-C[i-1]];
			} else {
				T[i][j] = T[i-1][j];
			}
		}
	}
	printArray(T, M, N);
	solution = T[M][N];
	for (unsigned int i = 0; i <= M; i++)
		delete [] T[i];
	delete [] T;
	return solution;
}

/**
 * Returns the min number of coins to form
 * the total = N
 */
int getMinCoins(int C[], int M, int N) {
	return 0;
}

int main() {
	int N = 250, M = 24;
	int C[] = {41, 34, 46, 9, 37, 32, 42, 21, 7, 13, 1, 24, 3, 43, 2, 23, 8, 45, 19, 30, 29, 18, 35, 11};
	cout<<"The Number of ways to form total = "<<N
	    <<" are: "<<getNumberOfWays(C, M, N)<<endl;

	cout<<"The Min number of coins required to make total = "
	    <<N<<" are: "<<getMinCoins(C, M, N)<<endl;

	//delete [] C;
	
	return 0;
}