#include "Graph.h"
#include <queue>
#include <stack>
#include <string.h>

void Graph::addEdge(int u, int v) {
	AdjNode *node = new AdjNode(v);
	node->next = array[u].head;
	array[u].head = node;

	if (isUndirected) {
		node = new AdjNode(u);
		node->next = array[v].head;
		array[v].head = node;
	}
}

void Graph::dfsUtil(int u, bool visited[]) {
	visited[u] = true;
	cout<<u<<" ";

	AdjNode *curr = array[u].head;
	while(curr) {
		int v = curr->data;
		if (!visited[v])
			dfsUtil(v, visited);
		curr = curr->next;
	}
}

/**
 * Performs complete dfs traversal of a
 * directed graph 
 * T(n) = O(E+V)
 */
void Graph::dfs() {
	bool *visited = new bool[V];
	memset(visited, 0, sizeof(visited));

    // Get the corresponding vertex connected
    // with the edge and see if it is visited
	for (int i = 0; i < V; i++) {
		cout<<"DFS Traversal from vertex: "<<i<<": ";
		if (visited[i]) continue;
		dfsUtil(i, visited);
		memset(visited, 0, sizeof(visited));
		cout<<endl;
	}
	delete [] visited;
}

void Graph::bfsUtil(int u, bool visited[]) {
	visited[u] = true;
	queue<int> q;
	q.push(u);

	while(!q.empty()) {
		u = q.front();
		q.pop();
		// Process the node
		cout<<u<<" ";

		AdjNode *curr = array[u].head;
		while (curr) {
			int v = curr->data;
			if (!visited[v]) {
				visited[v] = true;
				q.push(v);
			}
			curr = curr->next;
		}
	}
}

/**
 * Performs complete bfs traversal of a
 * directed graph 
 * T(n) = O(E+V)
 */
void Graph::bfs() {
	bool *visited = new bool[V];
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < V; i++) {
		cout<<"BFS Traversal from vertex: "<<i<<": ";
		if (visited[i]) continue;
		bfsUtil(i, visited);
		memset(visited, 0, sizeof(visited));
		cout<<endl;
	}
	delete [] visited;
}

void Graph::topologicalSortUtil(int u, bool *visited, stack<int> &stack) {
    // mark this vertex as visited
    visited[u] = true;

    // Get the corresponding vertex connected
    // with the edge and see if it is visited
    AdjNode *curr = array[u].head;
    while (curr) {
        int v = curr->data;
        // visit it if it is not visited
        if (!visited[v])
            topologicalSortUtil(v, visited, stack);
        curr = curr->next;
    }
    stack.push(u);
}

/**
 * Sorts DAG based on linear ordering
 * Maintains separate stack
 * Performs complete dfs traversal of a
 * directed graph 
 * T(n) = O(E+V)
 */
void Graph::topologicalSort() {
    // Initialize visited to false
    bool *visited = new bool[V];
    memset(visited, 0, sizeof(visited));
    stack<int> s;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            topologicalSortUtil(i, visited, s);
    }
    while (!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    delete [] visited;
}

bool Graph::isCyclicUtil(int u, bool visited[], bool recStack[]) {
	if (!visited[u]) {
		visited[u] = true;
		recStack[u] = true;

		AdjNode *curr = array[u].head;
		while (curr) {
			int v = curr->data;
			if (!visited[v] && isCyclicUtil(v, visited, recStack))
				return true;
			else if (recStack[v])
				return true;
		}
	} else {
		// if already visited remove the vertex from recursion stack
		recStack[u] = false;
		return false;
	}
	return false;
}


bool Graph::isCyclic() {
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	memset(visited, 0, sizeof(*visited));
	memset(recStack, 0, sizeof(*recStack));

	for(int i = 0; i < V; i++) {
		if (isCyclicUtil(i, visited, recStack))
			return true;
	}
	delete [] visited;
	delete [] recStack;
	return false;
}