/**
 * Rod Cutting
 * Given a length of rod, sample lengths and its 
 * corresponding profits find the maximum profit
 * that can be made given the length.
 * @Author: wajahat siddiqui
 */
#include <iostream>
using namespace std;

inline unsigned int max(unsigned int a, unsigned int b) {
	return (a > b) ? a : b;
}
void printArray(unsigned int **A, int M, int N) {
	for (unsigned int i = 0; i <= M; i++) {
		for (unsigned int j = 0; j <= N; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

/**
 * @param N is the length of the rod for which max profit to be found
 * @param M is the number of rods
 */
unsigned int findMaxProfit(int profit[], int M, int N) {
	unsigned int solution;
	unsigned int **T = new unsigned int *[M+1];
	for (int i = 0; i <= M; i++)
		T[i] = new unsigned int [N+1];
	for (int i = 0; i <= M; i++)
		T[i][0] = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (j >= i) {
				T[i][j] = max((T[i][j-i] + profit[i-1]), T[i-1][j]);
			} else {
				T[i][j] = T[i-1][j];
			}
		}
	}

	printArray(T, M, N);
	solution = T[M][N];

	for (int i = 0; i <= M; i++)
		delete [] T[i];
	delete [] T;
	return solution;
}

int main() {
	int N = 5; // Rod Length
	int profit[] = {2, 5, 7, 8};
	int M = sizeof(profit)/sizeof(profit[0]); // No. of rods
	cout<<"Maximum profit that can be made from Rod Length: "<<N<<" is: "
	    <<findMaxProfit(profit, M, N);
	return 0;
}