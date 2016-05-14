// Dijkstras Shortest Path Algorithm
#include <iostream>
#include <climits>
using namespace std;
#define V 9

int getMinVertex(bool sptset[], int distance[]) {
	int min = INT_MAX, min_index = 0;
	for (int i = 0; i < V; i++) {
		if (!sptset[i] && distance[i] < min) {
			min = distance[i];
			min_index = i;
		}
	}
	return min_index;
}

void print(int distance[]) {
	for (int i = 0; i < V; i++) {
		cout << distance[i] << " ";
	}
	cout<<endl;
}

void dijkstra(int graph[V][V], int src) {
	bool sptset[V];
	int distance[V];

	for (int i = 0; i < V; i++) {
		sptset[i] = false;
		distance[i] = INT_MAX;
	}

	distance[src] = 0;
	sptset[src] = true;

	for (int i = 0; i < V-1; i++) {
		int u = getMinVertex(sptset, distance);
		cout<<"u = "<<u<<endl;

		sptset[u] = true;

		// update the distance values of all
		// the vertices with this picked vertex u
		for (int v = 0; v < V; v++) {
			if (!sptset[v] && graph[u][v] && distance[u] != INT_MAX
				&& distance[u] + graph[u][v] < distance[v])
				distance[v] = distance[u] + graph[u][v];
		}
	}
	print(distance);
}

int main() {
int graph[V][V] = 	 {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    dijkstra(graph, 0);
	return 0;
}