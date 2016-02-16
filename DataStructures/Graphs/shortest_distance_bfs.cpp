#include <iostream>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#define UNIT_SIZE 6
#define UNREACHABLE -1
using namespace std;


struct AdjNode {
	int data;
	AdjNode *next;
	AdjNode(int _vertex) : data(_vertex) {
		next = NULL;
	}
};

struct AdjList {
	AdjNode *head;
};
class Graph {
private: 
	AdjList *array;
	int V, E;
	void bfsUtil(int start, bool visited[], int distance[]);
public:
	Graph(int _V, int _E) : V(_V+1), E(_E) {
		array = new AdjList[V];
		if (!array) {
			cout<<"Error could not initialize graph\n";
			exit(0);
		}
		for (int i = 0; i < V; i++)
			array[i].head = NULL;
	}

	~Graph() {
		for (int i = 0; i < V; i++) {
			AdjNode *curr = array[i].head, *prev = NULL;
			while (curr) {
				prev = curr;
				curr = curr->next;
				delete prev;
				prev = NULL;
			}
		}		
	}

	void addEdge(int u, int v);
	void bfs(int u);

	void printGraph() {
		for (int i = 1; i < V; i++) {
			cout<<"Adj list for vertex: "<<i<<": ";
			AdjNode *curr = array[i].head;
			while (curr) {
				cout<<curr->data<<" ";
				curr = curr->next;
			}
			cout<<endl;
		}
	}
};

void Graph::bfsUtil(int start, bool visited[], int distance[]) {
	int count = 1;
	visited[start] = true;
	queue<int> q;
	q.push(start);


	while(!q.empty()) {
		//count = 1;
		int u = q.front();
		q.pop();
		// Process the node
		AdjNode *curr = array[u].head;
		while (curr) {
			int v = curr->data;
			//if (!visited[v]) {
				//visited[v] = true;								
				distance[v] = UNIT_SIZE * count;
				q.push(v);
			//}
			/*if (distance[v] > UNIT_SIZE * count)
				distance[v] = UNIT_SIZE * count;
*/
			curr = curr->next;
		}
		count++;
	}
}

void Graph::bfs(int start) {
	bool *visited = new bool[V];
	int *distance = new int[V];
	memset(visited, 0, sizeof(visited));
	memset(distance, -1, sizeof(visited));
	bfsUtil(start, visited, distance);
	
	for (int i = 1; i < V; i++) {
		if (i == start) continue;
		if (distance[i] == -1) {
		 	cout<<UNREACHABLE<<" ";
		} else {
			cout<<distance[i]<<" ";
		}
	}
	delete [] visited;
}

void Graph::addEdge(int u, int v) {
	AdjNode *node = new AdjNode(v);
	node->next = array[u].head;
	array[u].head = node;
}

int main() {
	int T, V, E, x, y, start;
	freopen("shortest_distance_bfs.txt", "r", stdin);
	cin>>T;
	while (T--) {
		cin>>V>>E;
		Graph *graph = new Graph(V, E);
		for (int i = 0; i < E; i++) {
			cin>>x>>y;
			graph->addEdge(x, y);
		}
		cin>>start;
		//graph->printGraph();
		graph->bfs(start);
		delete graph;
		graph = NULL;
		cout<<endl;
	}
	return 0;
}
