#include <iostream>
#include <queue>
#include <cstdio>
#define UNIT_SIZE 6
using namespace std;

void printShortestDistances(int **mat, int V, int E, int start) {
	int *visited = new int[V+1];
	for (int i = 0; i < V+1; i++)
		visited[i] = -1; // initially mark as unvisited
	visited[start] = 0;
	queue<int> q;
	q.push(start);

	int u, count = 1;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int v = 1; v <= V; v++) {
			if (u != v && mat[u][v] && visited[v] == -1) {
				if (u != start) count++;
				visited[v] = count * UNIT_SIZE;
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (i != start) cout<<visited[i]<<" ";
	}
	delete [] visited;
}


int main() {
	int T, V, E, x, y, start;
	int **mat;
	//freopen("shortest_distance_bfs.txt", "r", stdin);
	cin>>T;
	while (T--) {
		cin>>V>>E;
		mat = new int*[V+1];
		for (int i = 0; i < V+1; i++)
			mat[i] = new int[V+1];

		for (int i = 0; i < V+1; i++)
			for(int j = 0; j < V+1; j++)
				mat[i][j] = 0;

		for (int i = 0; i < E; i++) {
			cin>>x>>y;
			mat[x][y] = mat[y][x] = 1;
		}
		cin>>start;
		printShortestDistances(mat, V, E, start);
		cout<<endl;

		for(int i = 0; i < V+1; i++)
			delete [] mat[i];
		delete [] mat;
	}
	return 0;
}
