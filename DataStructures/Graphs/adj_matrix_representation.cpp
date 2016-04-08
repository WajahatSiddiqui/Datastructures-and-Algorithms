#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct Graph {
    int V,E;
    int **adj;
};

Graph* createGraph(int V, int E) {
    Graph *G = new Graph();
    if (!G) return NULL;

    G->V = V;
    G->E = E;

    G->adj = new int*[G->V]; //row count
    for (int i = 0; i < G->V; i++) //column count
        G->adj[i] = new int[G->V];
    for (int i = 0; i < G->V; i++)
        for (int j = 0; j < G->V; j++)
            G->adj[i][j] = 0;
    int u, v;
    // 0 -> 1
    // 1 -> 2
    // 2 -> 3
    // 2 -> 0
    // 3 -> 0
    for (int i = 0; i < G->E; i++) {
        cout<<"Enter edge from u to v: ";
        cin>>u>>v;
        G->adj[u][v] = 1;
        // uncomment this for undirected graph
        // uses symmetry to initialize
        G->adj[v][u] = 1;
    }
    return G;
}

void print(Graph *G) {
    for (int u = 0; u < G->V; u++) {
        for (int v = 0; v < G->V; v++) {
            cout<<G->adj[u][v]<<" ";
        }
    cout<<endl;
    }
}

void dfsUtil(Graph *G, int u, bool *visited) {
    visited[u] = true;
    cout<<u<<" ";
    for (int i = 0; i < G->V; i++) {
        if (G->adj[u][i] && !visited[i]) {
            dfsUtil(G, i, visited);
        }
    }
}

void dfs(Graph *G) {
    bool *visited = new bool[G->V];
    for (int i = 0; i < G->V; i++) {
        if (!visited[i])
            dfsUtil(G, i, visited);
    }
    delete [] visited;
}

void bfsUtil(Graph *G, int u, bool *visited) {
    visited[u] = true;
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        int v = q.front();
        cout<<v<<" ";
        q.pop();

        for (int i = 0; i < G->V; i++) {
            if (G->adj[i][u] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void bfs(Graph *G) {
bool *visited = new bool[G->V];
    for (int i = 0; i < G->V; i++) {
        if (!visited[i])
            bfsUtil(G, i, visited);
    }
    delete [] visited;   
}

void deleteGraph(Graph *G) {
    if (!G || !G->adj) return;
    for (int i = 0; i < G->V; i++)
        delete [] G->adj[i];
    delete [] G->adj;

    delete G;
}

int main() {
    int V, E;
    cout<<"Enter #Vertices: ";
    cin>>V;
    cout<<"Enter #Edges: ";
    cin>>E;
    Graph *G = createGraph(4, 4);
    cout<<"Printing Adjacency Matrix\n";
    print(G);
    cout<<"DFS Traversal: ";
    dfs(G);
    cout<<"\nBFS Traversal: ";
    bfs(G);
    deleteGraph(G);
    return 0;
}
                    
