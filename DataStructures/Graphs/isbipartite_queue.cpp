#include <iostream>
#include <string.h>
#define V 4
using namespace std;

struct Queue {
    int *array;
    int size;
    int front, rear;
};

// creates queue of given size
Queue *createQueue(int size) {
    Queue *q = new Queue();
    if (!q) return NULL;
    q->size = size;
    q->array = new int[q->size];
    if (!q->array) return NULL;

    q->front = q->rear = -1;
    return q;
}

bool isFull(Queue *Q) {
    return (Q && (Q->front + Q->rear + 1 == Q->size));
}

bool isEmpty(Queue *Q) {
    return (Q && (Q->front == -1));
}

void enqueue(Queue *Q, int data) {
    if (isFull(Q)) return;
    Q->array[++Q->rear] = data;

    if (Q->front == -1)
        Q->front = Q->rear;
}

int dequeue(Queue *Q) {
    if (isEmpty(Q)) return -1;
    int data = Q->array[Q->front];

    if (Q->front == Q->rear)
        Q->front = Q->rear = -1;
    else
        Q->front++;
    return data;
}

void deleteQueue(Queue *Q) {
    if (!Q || !Q->array) return;
    delete [] Q->array;
    delete Q;
}

void printQueue(Queue *Q) {
    if (!Q || isEmpty(Q)) return;
    for (int i = Q->front; i <= Q->rear; i++)
        cout<<Q->array[i]<<" ";
    cout<<endl;
}


bool isBipartite(int Graph[][V], int src) {
    int color[V];
    memset(color, -1, sizeof(color));
    // set the color for source vertex
    color[src] = 1;

    Queue *queue = createQueue(100);
    enqueue(queue, src);

    while (!isEmpty(queue)) {
        int u = dequeue(queue);

        for (int v = 0; v < V; v++) {
            // Assign the color to the neighbouring
            // vertex if it is not already assiged
            if (Graph[u][v]) {
                if (color[v] == -1) {
                color[v] = 1 - color[u];
                enqueue(queue, v);
                } else if (color[v] == color[u]) {
                    deleteQueue(queue);
                    return false;
                }
            }
        }
    }
    deleteQueue(queue);
    return true;
}

int main() {
    int Graph[][V] = { {0, 1, 0, 1},
                      {1, 0, 1, 0},
                      {0, 1, 0, 1},
                      {1, 0, 1, 0}};
    isBipartite(Graph, 0) ? cout<<"YES" : cout<<"NO";

    return 0;
}
