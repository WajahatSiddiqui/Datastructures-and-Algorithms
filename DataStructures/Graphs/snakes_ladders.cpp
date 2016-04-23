// http://www.geeksforgeeks.org/snake-ladder-problem-2/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct QNode {
	int v; // vertex
	int d; //distance;
};

int getMinDice(int moves[], int N) {
	bool *visited = new bool[N];
	memset(visited, false, sizeof(visited));

	queue<QNode> q;
	QNode qN = {0, 0}; // start node
	q.push(qN);
	visited[0] = true;
	QNode qE;
	while (!q.empty()) {
		qE = q.front();
		cout<<"pop: "<<qE.v<<" "<<qE.d<<endl;
		q.pop();

		int v = qE.v;

		if (v == N-1) break;

		for (int j = v+1; j <= v+6 && j < N; j++) {
			if (!visited[j]) {
				QNode qN;
				qN.d = qE.d+1;
				visited[j] = true;
				if (moves[j] != -1) {
					qN.v = moves[j];
				} else {
					qN.v = j;
				}
				cout<<"push: "<<qN.v<<" "<<qN.d<<endl;
				q.push(qN);
			}
		}
	}
	delete [] visited;
	return qE.d;
}

int main() {
	int N = 30; // Board Size;
	int moves[N];
	memset(moves, -1, sizeof(moves));

	// snakes positions
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 9;
	moves[18] = 6;

	// ladder positions
	moves[10] = 25;
	moves[2] = 21;
	moves[4] = 7;
	moves[19] = 28;

	cout<<"The min number of dices required to reach destination is: "<<getMinDice(moves, N)<<endl;
	return 0;
}