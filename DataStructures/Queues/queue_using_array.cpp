#include <iostream>
using namespace std;

struct Queue {
    int *array;
    int front, rear;
    int size;
};

Queue* createQueue(int size) {
    Queue *queue = new Queue();
    if (!queue) return NULL;

    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = new int[queue->size];

    if (!queue->array) return NULL;

    return queue;
}

bool isFull(Queue* queue) {
    return (queue && (queue->rear + 1 == queue->size));
}

bool isEmpty(Queue* queue) {
    return (queue && queue->front == -1);
}

void enqueue(Queue *queue, int data) {
    if (isFull(queue)) return;

    queue->array[++queue->rear] = data;

    if (queue->front == -1)
        queue->front = queue->rear;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) return -1;

    int data = queue->array[queue->front];

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return data;
}

void deleteQueue(Queue *queue) {
    if (isEmpty(queue)) return;
    delete [] queue->array;
    delete queue;
}

void printQueue(Queue *queue) {
    if (isEmpty(queue)) return;

    for (int i = queue->front; i <= queue->rear; i++) {
        cout<<queue->array[i]<<" ";
    }
    cout<<endl;
}

size_t size(Queue *queue) {
    return isEmpty(queue) ? 0 : (queue->rear+1 - queue->front);
}

int main() {
    Queue *queue = createQueue(10);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);
    enqueue(queue, 11);

    printQueue(queue);

    int del = 5;
    cout<<"Dequeue 5 elements\n";
    while (del--) {
        cout<<dequeue(queue)<<" ";
    }
    cout<<endl;

    cout<<"Size of queue: "<<size(queue)<<endl;
    printQueue(queue);


    del = 6;
    cout<<"Dequeue 6 elements\n";
    while (del--) {
        cout<<dequeue(queue)<<" ";
    }
    cout<<endl;

    cout<<"Size of queue: "<<size(queue)<<endl;
    printQueue(queue);

    deleteQueue(queue);

    return 0;
}
    


