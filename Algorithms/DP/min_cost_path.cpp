// Min Cost Path
#include <iostream>
#include <cstdio>
#define SIZE 3
using namespace std;


void print(int **T, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << T[i][j] << " ";
		}
		cout<<endl;
	}
	cout<<endl;	
}

int min(int a, int b) {
	return a < b ? a : b;
}

int getMinCostPath(int **path, int N, int M) {
	int solution = 0;
	int **T = new int*[N];
	for (int i = 0; i < N; i++)
		T[i] = new int[M];
	T[0][0] = path[0][0];
	// fill first row
	for (int i = 1; i < M; i++) {
		T[0][i] = path[0][i] + T[0][i-1];
	}
	// fill first col
	for (int i = 1; i < N; i++) {
		T[i][0] = path[i][0] + T[i-1][0];
	}
	
	//print(T, N, M);
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			T[i][j] = path[i][j] + min(T[i-1][j], T[i][j-1]);
		}
	}
	print(T, N, M);
	solution = T[N-1][M-1];

	for (int i = 0; i < N; i++)
		delete [] T[i];
	delete [] T;
	return solution;
}

int main() {
	int N, M;
	int **path;
	freopen("min_cost_path.txt", "r", stdin);
	cin >> N >> M;
	path = new int*[N];
	for (int i = 0; i < N; i++)
		path[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin>>path[i][j];
		}
	}

	print(path, N, M);
	cout<<"Min cost path = " <<getMinCostPath(path, N, M)<<endl;
	for (int i = 0; i < N; i++)
		delete [] path[i];
	delete [] path;
	return 0;
}