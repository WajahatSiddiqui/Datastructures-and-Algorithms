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
	Node *next;
	Node(int x_, int y_) : x(x_), y(y_) {
		next = NULL;
	}
};

struct Queue {
	Node *front, *rear;
	Queue() {
		front = rear = NULL;
	}
};

bool isEmpty(Queue *q) {
	return q && q->front == NULL;
}

void enqeue(Queue *q, int x, int y) {
	if (!q) return;
	Node *item = new Node(x, y);
	if (isEmpty(q)) {
		q->rear = item;
		q->front = q->rear;
	} else {
		q->rear->next = item;
		q->rear = item;
	}
	cout<<"E: "<<x<<" " <<y<<endl;
}

void dequeue(Queue *q, int &x, int &y) {
	if (isEmpty(q)) return;
	Node *temp = q->front;
	x = temp->x;
	y = temp->y;
	q->front = q->front->next;
	delete temp;
	temp = NULL;
	cout<<"D: "<<x<<" " <<y<<endl;
}

void printQueue(Queue *q) {
	if (isEmpty(q)) return;
	Node *r = NULL;
	for (r = q->front; r != q->rear; r = r->next)
		cout<<r->x<<" "<<r->y<<endl;
	cout<<r->x<<" "<<r->y<<endl;
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
	int x = 0, y = 0, count = 0, next_x, next_y;
	int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

	bool isMoved = false, isFound = false;
	enqeue(q, R, C);
	visited[R][C] = true;

	while (!isEmpty(q)) {
		dequeue(q, x, y);

		for (int move = 0; move < 8; move++) {
			next_x = x + dx[move];
			next_y = y + dy[move];
			if (next_x == S && next_y == K) {
				cout<<"H: "<<next_x<<" "<<next_y<<endl;
				count++;
				if (!isFound) isFound = !isFound;
				break;
			}
			if (canMove(N, M, next_x, next_y, visited)) {
				visited[next_x][next_y] = true;				
				enqeue(q, next_x, next_y);
				if (move + 1 == 8) count++;
			}
		}
		if (isFound) break;
		//printQueue(q);
		cout<<count<<endl;
	}
	printVisited(visited, N, M);

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
