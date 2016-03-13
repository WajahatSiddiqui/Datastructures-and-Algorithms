#include <iostream>
#include <limits.h>
#include <queue>
#include <cstdio>
#define UNIT_SIZE 6
using namespace std;

bool hasElement(queue<int> &q, int v) {
	queue<int> newq = q;
	while (!newq.empty()) {
		if (newq.front() == v) return true;
		newq.pop();
	}
	return false;
}

void printShortestDistances(int **mat, int V, int E, int start) {
	int *distance = new int[V+1];
	for (int i = 0; i < V+1; i++)
		distance[i] = INT_MAX; // initially mark as unreachable
	distance[start] = 0;
	queue<int> q;
	q.push(start);

	int u;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int v = 1; v <= V; v++) {
			if (mat[u][v]&& distance[v] > distance[u] + UNIT_SIZE) {
				distance[v] = distance[u] + UNIT_SIZE;
				if (!hasElement(q, v))
					q.push(v);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (i == start) continue;
		if (distance[i] == INT_MAX)
			cout<<"-1"<<" ";
		else
			cout<<distance[i]<<" ";

	}
	delete [] distance;
}


int main() {
	int T, V, E, x, y, start;
	int **mat;
	freopen("shortest_distance_bfs.txt", "r", stdin);
	cin>>T;
	while (T--) {
		cin>>V>>E;
		mat = new int*[V+1];
		for (int i = 0; i < V+1; i++)
			mat[i] = new int[V+1];

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
