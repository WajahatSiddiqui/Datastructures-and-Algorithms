/**
 * Floyd Warshall's Algorithm for All Pairs shortest path problem
 */
 #include <iostream>
 #include <limits.h>
 #define V 4
 #define INF INT_MAX
 using namespace std;

void print(int array[][V]) {
 	for (int i = 0; i < V; i++) {
 		for (int j = 0; j < V; j++) {
 			if (array[i][j] == INF)
 				cout<<"INF ";
 			else
 				cout<<array[i][j]<<" ";
 		}
 		cout<<endl;
 	}
 }

 void floyd_warshall(int graph[][V]) {
 	int dist[V][V], i, j, k;

 	for (i = 0; i < V; i++)
 		for(j = 0; j < V; j++)
 			dist[i][j] = graph[i][j];

 	for (k = 0; k < V; k++) {
 		for (j = 0; j < V; j++) {
 			for (i = 0; i < V; i++) {
 				if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
 					dist[i][j] = dist[i][k] + dist[k][j];
 			}
 		}
 	}
 	print(dist);
 }

 int main() {
 	int graph[][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                  	  };
    cout<<"Input Graph: \n";
    print(graph);
    cout<<"Solution: \n";
    floyd_warshall(graph);
    return 0;
}
