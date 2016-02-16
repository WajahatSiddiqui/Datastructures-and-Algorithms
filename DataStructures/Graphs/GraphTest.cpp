#include "Graph.h"

int main() {
	Graph *graph = new Graph(4, 6);

    graph->addEdge(0, 1);
    graph->addEdge(1, 2);
    graph->addEdge(2, 0);
    graph->addEdge(2, 3);
    graph->addEdge(3, 3);
    graph->addEdge(0, 2);
    graph->printGraph();

    // Do DFS Traversal
    graph->dfs();
    // Do BFS Traversal
    graph->bfs();
    delete graph;
    graph = NULL;

    graph = new Graph(6, 6);
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