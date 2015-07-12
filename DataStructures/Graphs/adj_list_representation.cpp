/*
 *
Enter edge (u, v): 0 1
Enter edge (u, v): 0 4
Enter edge (u, v): 1 4
Enter edge (u, v): 1 3
Enter edge (u, v): 1 2
Enter edge (u, v): 2 3
Enter edge (u, v): 3 4
Adjacency List of vertex: 0
4 1 
Adjacency List of vertex: 1
2 3 4 0 
Adjacency List of vertex: 2
3 1 
Adjacency List of vertex: 3
4 2 1 
Adjacency List of vertex: 4
3 1 0 
*/ 
#include <iostream>
using namespace std;

struct AdjNode {
    int vertex;
    AdjNode *next;
};

struct AdjList {
    AdjNode *head;
};

struct Graph {
    int V,E;
    AdjList *array;
};

AdjNode* newNode(int data) {
    AdjNode *newAdjNode = new AdjNode();
    newAdjNode->vertex = data;
    newAdjNode->next = NULL;
}

void addEdge(Graph *graph, int src, int dest) {
    if (!graph) return;
    // create a for dest, and add the next to the
    // head's pointer
    // update the head with the dest node
    AdjNode *node = newNode(dest);
    node->next = graph->array[src].head;
    graph->array[src].head = node;

    // create a symmetry for undirected graph
    // as above rev src with dest.
    node = newNode(src);
    node->next = graph->array[dest].head;
    graph->array[dest].head = node;
}

Graph* createGraph(int V, int E) {
    Graph *graph = new Graph();
    if (!graph) return NULL;
    graph->V = V;
    graph->E = E;

    graph->array = new AdjList[V];
    if (!graph->array) return NULL;

    for (int i = 0; i < V; i++)
        graph->array[i].head = NULL;

    int u, v;
    for(int i = 0; i < E; i++) {
        cout<<"Enter edge (u, v): ";
        cin>>u>>v;
        addEdge(graph, u, v);
    }
    return graph;
}

void printGraph(Graph *graph) {
    if (!graph) return;
    AdjNode *curr = NULL;
    for (int i = 0; i < graph->V; i++) {
        cout<<"Adjacency List of vertex: "<<i<<endl;
        curr = graph->array[i].head;
        while(curr) {
            cout<<curr->vertex<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
}

void deleteGraph(Graph *graph) {
    if (!graph) return;
    AdjNode *temp = NULL;
    for (int i = 0; i < graph->V; i++) {
        temp = graph->array[i].head;
        AdjNode *curr = temp, *prev = NULL;
        while (curr) {
            prev = curr;
            curr = curr->next;
            delete prev;
        }
        delete temp;
    }
    delete graph;
}

int main() {
    Graph *graph = createGraph(5, 7);
    printGraph(graph);
    deleteGraph(graph);

    return 0;
}
