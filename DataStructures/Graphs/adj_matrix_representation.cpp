#include <iostream>
#include <string.h>
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
        //G->adj[v][u] = 1;
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

void deleteGraph(Graph *G) {
    if (!G || !G->adj) return;
    for (int i = 0; i < G->V; i++)
        delete [] G->adj[i];
    delete [] G->adj;

    delete G;
}

int main() {
    Graph *G = createGraph(4, 5);
    print(G);
    deleteGraph(G);
    return 0;
}
                    
