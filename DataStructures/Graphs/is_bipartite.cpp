// http://www.geeksforgeeks.org/bipartite-graph/
#include<iostream>
#include<queue>
#define V 4
using namespace std;

bool isBipartite(int Graph[][V], int src) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = -1;
    color[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            if (Graph[u][v] && color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (Graph[u][v] && color[u] == color[v]) return false;
        }
    }
    return true;
}

int main() {
    int Graph[][V] = {{0, 1, 0, 1},
                      {1, 0, 1, 0},
                      {0, 1, 0, 1},
                      {1, 0, 1, 0}};
    isBipartite(Graph, 0) ? cout<<"Yes" : cout<<"No";

    return 0;
}
