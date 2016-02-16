/**
 * Graph - A Graph is a set of <V, E>
 * Represents Graph as a Adjancency List
 * Performs operations like DFS, BFS, Topological sort
 */

#ifndef __GRAPH__
#define __GRAPH__

#include <iostream>
#include <stack>
#include <stdlib.h>
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
	bool isUndirected;

	// Utilities
	void dfsUtil(int i, bool visited[]);
	void bfsUtil(int i, bool visited[]);
	void topologicalSortUtil(int i, bool visited[], stack<int> &s);

public:
	Graph(int _V, int _E, bool _isUndirected = false)
	 : V(_V)
	 , E(_E)
	 , isUndirected(_isUndirected) {
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

	// Operations
	void dfs();
	void bfs();
	void topologicalSort();


	void addEdge(int u, int v);
	void printGraph() {
		for (int i = 0; i < V; i++) {
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

#endif //__GRAPH__
