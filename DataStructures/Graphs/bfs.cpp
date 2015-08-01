/**
 * Breadth First Traversal of a Directed Graph
 */
#include <iostream>
#include <string.h>
#include <queue>
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

void bfs(Graph *graph, int u, bool *visited) {
    if (!graph) return;

    // mark this vertex as visited
    visited[u] = true;

    // enqueue the given node into queue
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        // Process the front node.
        cout<<u<<" ";

        // Get the corresponding vertex connected
        // with the edge and see if it is visited
        Node *curr = graph->adjList[u].adjNode;
        while (curr) {
            int v = curr->data;
            // visit it if it is not visited in level order
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
void bfsTraversal(Graph *graph) {
    if (!graph) return;
    // Initialize visited to false
    bool *visited = new bool[graph->V];
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    for (int i = 0; i < graph->V; i++) {
        // comment below to find bfs of all vertices
        // complete bfs traversal
        if (visited[i]) continue;
        cout<<"bfs Traversal from vertex "<<i<<": ";
        // call bfs for each vertex which is not already
        // visited
        bfs(graph, i, visited);
        // enable this to get bfs of all vertices printed
        memset(visited, 0, sizeof(visited));
        cout<<endl;
    }
}


int main() {

    Graph *graph = createGraph(4, 6);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);
    addEdge(graph, 0, 2);
    printGraph(graph);
    bfsTraversal(graph);
    deleteGraph(graph);

    return 0;
}
