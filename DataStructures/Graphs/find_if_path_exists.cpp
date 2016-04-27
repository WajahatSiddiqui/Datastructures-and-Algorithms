//http://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph/
#include <iostream>
using namespace std;
#define N 4

bool pathExists(int Graph[][N], int u, int v, bool *visited) {
	bool isExists = false;
	visited[u] = true;
	for (int i = 0; i < N; i++) {
		if (Graph[u][i] && !visited[i]) {
			if (i == v) return true;
			isExists = pathExists(Graph, i, v, visited);
		}
	}
	return isExists;
}

int main() {
	int Graph[][N] = { {0, 1, 1, 0},
					  {0, 0, 1, 0},
					  {1, 0, 0, 1},
					  {0, 0, 0, 1} };

	int u = 2, v = 3;
	bool *visited = new bool[N];
	if (pathExists(Graph, u, v, visited))
		cout<<"Path exists from "<<u<<"->"<<v<<endl;
	else
		cout<<"Path doesn't exists from "<<u<<"->"<<v<<endl;
	delete [] visited;
	return 0;
}