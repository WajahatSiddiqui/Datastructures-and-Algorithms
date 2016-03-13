/**
 * 0/1 Knapsack problem:
 * Given a bag which can only take certain weight W. Given list of items with their weights and price.
 * How do you fill this bag to maximize value of items in the bag.
 * 0 -> pick the item, 1-> dont pick the item
 */
#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

void printArray(unsigned int **T, int M, int N) {
	for (unsigned int i = 0; i <= M; i++) {
		for (unsigned int j = 0; j <= N; j++){
			cout<<T[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int knapsack(int w[], int v[], int M, int N) {
	unsigned int solution = 0;
	unsigned int **T = new unsigned int*[M+1];
	for (int i = 0; i <= M; i++)
		T[i] = new unsigned int[N+1];

	//printArray(T, M, N);

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (j < w[i-1]) {
				T[i][j] = T[i-1][j];
			} else {
				T[i][j] = max((v[i-1] + T[i-1][j-w[i-1]]), T[i-1][j]);
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
	int w[] = {1, 3, 4, 5}; // weights
	int v[] = {1, 4, 5, 7}; // values 
	int M = sizeof(w)/sizeof(w[0]); // size of w or value
	int N = 7; // total weight of sack
	cout<<knapsack(w, v, M, N)<<endl;
	return 0;
}