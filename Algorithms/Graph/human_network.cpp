/*A social science research institute is going tostudy human network by using several methods of measurement. To help theresearchers, write a program that analyzes the following to find out who is themost influential person is in the human network given.
Provided, N is the number of nodes in the humannetwork(graph).
 Closeness Centrality(CC): Closeness indicates howclose a user is to all other people on network. Therefore, user i’s CC(i) iscalculated as follows.
CC(i) = ∑ j dist(i,j) provided, dist(i,j) is the shortest distance from node i to node j.
 
Ex. 1)
 
[Constraints]

There is no edge connecting the node itself in thehuman network given in input. In addition, the human network consists of oneconnected component provided the maximum number of users of the human networkis 1,000 or less.

Test cases are composed of the following groups.  

 

Group1 When there is no cycle, and N <= 10

 Group 2 When there is no cycle and 10< N <= 100

 Group3 When there is a cycle(s) and N <=10

 Group 4 When there is a cycle(s) and 10< N <= 100

 Group 5 When all cases exist and 100< N <= 1000

 

[Input]

The total number of test cases, T, is given inthe first line. From the next line, T test cases are given. Each test case isgiven line-by-line in order of the number of people, N (a positive integer)followed by the adjacent matrix of human network row-by-row. The numbers areseparated by a blank space. 


[Output]

Print answers for each of the test cases throughout T test cases. Starteach line with ‘#x’, leave a blank space, and print out in one line the leastvalue among the values of CC of the human graph given for each test case.

[Input/output example]

Input(a total of T test cases are given line-by-line.)
 

20                                                     <- Total number of test cases T
5 0 1 1 0 0 1 0 1 1 1 1 1 0 0 0 0 1 0 0 0 0 1 0 0 0    <- 1st test case   N = 5
5 0 0 1 1 0 0 0 1 0 0 1 1 0 0 1 1 0 0 0 1 0 0 1 1 0    <- 2nd test case   N = 5
 
  
 
 Output(consisting of T lines in total)

#1 4
#2 5
…
*/ 

#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;

class Graph {
private:
	int **m_adj;
	int V;
	int E;
public:
	Graph(int N) : V(N) {
		m_adj = new int*[V];
		for (int i = 0; i < V; i++)
			m_adj[i] = new int[V];
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				m_adj[i][j] = 0;
	}

	~Graph() {
		for (int i = 0; i < V; i++)
			delete [] m_adj[i];
		delete [] m_adj;
	}

	void getAdjacencyMatrix() {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				cin>>m_adj[i][j];
				if (m_adj[i][j] == 1) E++;
			}
		}
		E = E / 2;
	}

	void printAdjacencyMatrix() {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				cout<<m_adj[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	void floydWarshall();

	int findHumanNetwork(){ return 0; }
};

void Graph::floydWarshall() {
	int dist[V][V], i, j, k;
	  for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
        		dist[i][j] = m_adj[i][j];
        }
    }

    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				cout<<dist[i][j]<<" ";
			}
			cout<<endl;
		}
}

int main() {
	int T, V;
	freopen("human_network.txt", "r", stdin);
	cin>>T;
	Graph *graph = NULL;
	for (int i = 1; i <= T; i++) {
		cin>>V;
		graph = new Graph(V);
		graph->getAdjacencyMatrix();
		//graph->printAdjacencyMatrix();
		graph->floydWarshall();
		cout<<"# "<<T<<" "<<graph->findHumanNetwork()<<endl;
		delete graph;
	}
	return 0;	
}