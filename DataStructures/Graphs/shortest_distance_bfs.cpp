#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#define UNIT_SIZE 6
using namespace std;

struct QNode {
	int u;
	int d; // distance
};

void print(int *A, int N) {
	for (int i = 0; i < N; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void printAdj(int **adj, int V) {
	for (int i = 0; i <= V; i++) {
		for (int j = 0; j <= V; j++) {
			cout << adj[i][j] << " ";
		}
		cout<<endl;
	}
}

void printShortestDistances(int **mat, int V, int E, int start) {
	int *distance = new int[V+1];
	for (int i = 0; i < V+1; i++)
		distance[i] = -1;
	distance[start] = 0;
	//print(distance, V+1);
	QNode qN = {start, 0};
	queue<QNode> q;
	q.push(qN);
	QNode qE;
	while (!q.empty()) {
		qE = q.front();
		q.pop();
		//cout<<qE.u<<" "<<qE.d<<endl;
		for (int v = 1; v <= V; v++) {
			if (mat[qE.u][v] && distance[v] == -1) {
				distance[v] = qE.d + UNIT_SIZE;
				QNode qNN = {v, distance[v]};
				q.push(qNN);
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (i == start) continue;
		cout << distance[i] << " ";
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
		//printAdj(mat, V+1);
		//cout<<endl;
		cin>>start;
		printShortestDistances(mat, V, E, start);
		cout<<endl;
		for(int i = 0; i < V+1; i++)
			delete [] mat[i];
		delete [] mat;
	}
	return 0;
}
