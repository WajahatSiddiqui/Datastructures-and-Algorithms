/**
 * Chess NxM
 * Attacker R, C
 * Defender S, K
 * Output minimum number of moves to catch a defending piece by the attacker
 * if it is not possible output -1
 */
#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int x, y;
    int d;
    Node *next;

    Node(int _x, int _y, int _d)
     : x(_x), y(_y), d(_d) { next = NULL; }
};

class Queue {
    Node *fr, *rr;
public:
    Queue() : fr(NULL), rr(NULL) {}
    ~Queue() {
        Node *curr = fr;
        Node *temp = NULL;
        while (curr) {
            temp = curr;
            curr = curr->next;
            delete temp;
            temp = NULL;
        }
        if (fr = NULL) rr = NULL;
    }

    Node* front() { return fr; }
    Node* rear() { return rr; }

    bool isEmpty() { return fr == NULL && rr == NULL; }

    void enqueue(Node *n);
    void dequeue();
};

void Queue::enqueue(Node *n) {
    if (isEmpty()) {
        fr = rr = n;
    } else {
        rr->next = n;
        rr = n;
    }
}

void Queue::dequeue() {
    if (isEmpty()) return;
    Node *temp = fr;
    fr = fr->next;
    delete temp;
    temp = NULL;
    if (fr == NULL)
        rr = NULL;
}


bool canMove(int N, int M, int x, int y, bool **visited) {
	return x >= 1 && x <= N && y >= 1 && y <= M && !visited[x][y];
}

void printVisited(bool **visited, int N, int M) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}
}

int findNumberOfMoves(int N, int M, int R, int C, int S, int K) {
	bool **visited = new bool*[N + 1];
	for (int i = 0; i < M + 1; i++)
		visited[i] = new bool[N + 1];

	for (int i = 0; i <= M; i++)
	for (int j = 0; j <= N; j++)
		visited[i][j] = false;
	//printVisited(visited, N, M);

	Queue *q = new Queue();
	int x = 0, y = 0, d = 0, count = 0;
	bool isFound = false;
	int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
	int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
	q->enqueue(new Node(R, C, 0));
	visited[R][C] = true;
	Node *f = NULL;

	while (!q->isEmpty() && !isFound) {
		f = q->front();
		x = f->x;
		y = f->y;
		d = f->d;
		q->dequeue();
		for (int i = 0; i < 8; i++) {
			if (canMove(N, M, x + dx[i], y + dy[i], visited)) {
				if (x + dx[i] == S && y + dy[i] == K) {
					count = d+1;
					if (!isFound) isFound = !isFound;
					break;
				}
				visited[x + dx[i]][y + dy[i]] = true;
				Node *qE = new Node(x + dx[i], y + dy[i], d + 1);
				q->enqueue(qE);
			}
		}
	}
	//printVisited(visited, N, M);
	for (int i = 0; i <= M; i++)
		delete[] visited[i];
	delete[] visited;

	delete q;

	return isFound ? count : -1;
}

int main() {
	int T, N, M, R, C, S, K;
	freopen("chess.txt", "r", stdin);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cin >> R >> C >> S >> K;
		cout << findNumberOfMoves(N, M, R, C, S, K) << endl;
	}
	return 0;
}
