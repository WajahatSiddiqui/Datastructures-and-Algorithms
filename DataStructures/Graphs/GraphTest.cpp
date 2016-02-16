#include "Graph.h"

int main() {
	Graph *graphC = new Graph(4, 6);

    graphC->addEdge(0, 1);
    graphC->addEdge(1, 2);
    graphC->addEdge(2, 0);
    graphC->addEdge(2, 3);
    graphC->addEdge(3, 3);
    graphC->addEdge(0, 2);
    graphC->printGraph();

    // Do DFS Traversal
    graphC->dfs();
    // Do BFS Traversal
    graphC->bfs();

    if (graphC->isCyclic()) {
        cout<<"Graph is cyclic\n";
    } else {
        cout<<"Graph is ACyclic\n";
    }

    Graph *acycle = new Graph(3, 2);
    acycle->addEdge(0, 1);
    acycle->addEdge(1, 2);
    if (acycle->isCyclic()) {
        cout<<"Graph is cyclic\n";
    } else {
        cout<<"Graph is ACyclic\n";
    }


    
    Graph *graph = new Graph(6, 6);
    graph->addEdge(2, 3);
    graph->addEdge(3, 1);
    graph->addEdge(4, 0);
    graph->addEdge(4, 1);
    graph->addEdge(5, 0);
    graph->addEdge(5, 2);
    graph->printGraph();
    cout<<"Topological sorted order: ";
    graph->topologicalSort();
    delete graph;
    graph = NULL;

    graph = new Graph(8, 8);
    graph->addEdge(0, 3);
    graph->addEdge(0, 4);
    graph->addEdge(1, 3);
    graph->addEdge(2, 4);
    graph->addEdge(2, 7);
    graph->addEdge(3, 5);
    graph->addEdge(3, 6);
    graph->addEdge(4, 6);
    graph->printGraph();
    cout<<"Topological sorted order: ";
    graph->topologicalSort();
    delete graph;

    return 0;
}