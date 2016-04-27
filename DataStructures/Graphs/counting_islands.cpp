//http://www.geeksforgeeks.org/find-number-of-islands/
#include <iostream>
#define V 5
using namespace std;

bool isSafe(int M[][V], int x, int y, bool **visited) {
	return x >= 0 && x < V && y >= 0 && y < V && M[x][y] == 1 && !visited[x][y];
}

/**
 * Find the 8-connected components
 * T(n) = O(NxN) N - rowsxcols of a matrix
 */

void dfs(int M[][V], int x, int y, bool **visited) {
	static int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
	static int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	visited[x][y] = true;
	for (int i = 0; i < 8; i++) {
		if (isSafe(M, x+dx[i], y+dy[i], visited))
			dfs(M, x+dx[i], y+dy[i], visited);
	}
}

int getIslands(int M[][V]) {
	bool **visited = new bool*[V];
	for (int i = 0; i < V; i++)
		visited[i] = new bool[V];

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			visited[i][j] = false;

	int islands = 0;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (M[i][j] && !visited[i][j]) {
				dfs(M, i, j, visited);
				islands++;
			}

		}
	}
	return islands;
}

int main() {
    int M[][V]= {  {1, 1, 0, 0, 0},
			        {0, 1, 0, 0, 1},
			        {1, 0, 0, 1, 1},
			        {0, 0, 0, 0, 0},
			        {1, 0, 1, 0, 1}};

	cout<<"No. of islands = "<<getIslands(M)<<endl;

	return 0;
}