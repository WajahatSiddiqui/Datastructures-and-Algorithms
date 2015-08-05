/**
 * Implement Topological sort
 * Sorts DAG based on linear ordering
 * Maintains separate stack
 */
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct AdjList {
    Node *adjNode;
};

struct Graph {
    int V, E;
    AdjList *adjList;
};


Graph* createGraph(int V, int E) {
    Graph *graph = new Graph();
    if (!graph) return NULL;

    graph->V = V;
    graph->E = E;

    graph->adjList = new AdjList[V];
    if (!graph->adjList) return NULL;

    for (int i = 0; i < V; i++)
        graph->adjList[i].adjNode = NULL;
    return graph;
}

void addEdge(Graph *graph, int u, int v) {
    if (!graph) return;
    Node *node = new Node();
    node->data = v;
    node->next = graph->adjList[u].adjNode;
    graph->adjList[u].adjNode = node;
}

void printGraph(Graph *graph) {
    if (!graph) return;
    cout<<" * * * Print Graph * * *\n";
    for (int i = 0; i < graph->V; i++) {
        cout<<"Edge from vertex "<<i<<": ";
        Node *curr = graph->adjList[i].adjNode;
        while (curr) {
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
}

void deleteGraph(Graph *graph) {
    if (!graph || !graph->adjList) return;
    
    for (int i = 0; i < graph->V; i++) {
        Node *curr = graph->adjList[i].adjNode;
        Node *prev = NULL;
        while (curr) {
            prev = curr;
            curr = curr->next;
            delete prev;
            prev = NULL;
        }
    }
    delete [] graph->adjList;
    delete graph;
    graph = NULL;
}

void topologicalSortUtil(Graph *graph, int u, bool *visited, stack<int> &stack) {
    if (!graph) return;

    // mark this vertex as visited
    visited[u] = true;

    // Get the corresponding vertex connected
    // with the edge and see if it is visited
    Node *curr = graph->adjList[u].adjNode;
    while (curr) {
        int v = curr->data;
        // visit it if it is not visited
        if (!visited[v])
            topologicalSortUtil(graph, v, visited, stack);
        curr = curr->next;
    }
    stack.push(u);
}

/**
 * Performs complete dfs traversal of a
 * directed graph 
 * T(n) = O(E+V)
 */
void topologicalSort(Graph *graph) {
    if (!graph) return;
    // Initialize visited to false
    bool *visited = new bool[graph->V];
    stack<int> s;
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, s);
    }
    while (!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    delete [] visited;
}


int main() {

    Graph *graph = createGraph(6, 6);

    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 5, 0);
    addEdge(graph, 5, 2);
    printGraph(graph);
    cout<<"Topological sorted order: ";
    topologicalSort(graph);
    deleteGraph(graph);
    graph = NULL;
    graph = createGraph(8, 8);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 7);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 6);
    printGraph(graph);
    cout<<"Topological sorted order: ";
    topologicalSort(graph);
    deleteGraph(graph);

    return 0;
}
