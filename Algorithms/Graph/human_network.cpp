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

//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#define INF 99999
using namespace std;

int adj[1001][1001];

void printArray(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}
int findHumanNetwork(int N) {
	int min = INF, sum = 0;
	//printArray(N);
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (adj[i][k] + adj[k][j] < adj[i][j])
					adj[i][j] = adj[i][k] + adj[k][j];
				if (i != j)	sum += adj[i][j];
			}
			if (i == 0) min = sum;
			if (sum < min) min = sum;
			sum = 0;

		}
	}
	//printArray(N);
	return min;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("human_network.txt", "r", stdin);
	cin >> T;
	int N;
	/*
	Read each test case from standard input.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> adj[i][j];
				if (i != j && adj[i][j] == 0) adj[i][j] = INF;
			}
		}

		cout << "#" << test_case <<" "<<findHumanNetwork(N)<< endl;
	}
	return 0;//Your program should return 0 on normal termination.
}