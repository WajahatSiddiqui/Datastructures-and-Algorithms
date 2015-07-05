/**
 * Implement Queue using LinkedList
 */
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Queue {
    Node *front, *rear;
};

Queue* create() {
    Queue *Q = new Queue();
    if (!Q) return NULL;

    Q->front = Q->rear = NULL;
    return Q;
}

void enqueue(Queue *Q, int data) {
    if (!Q) return;
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (Q->rear) Q->rear->next = newNode;
    Q->rear = newNode;

    if (Q->front == NULL)
        Q->front = Q->rear;
}

int dequeue(Queue *Q) {
    if (!Q || !Q->front) return 0;
    int data = Q->front->data;
    Node *temp = Q->front;
    Q->front = Q->front->next;
    delete temp;
    temp = NULL;
    return data;
}

int size(Queue *Q) {
    if (!Q) return 0;
    int count = 0;
    Node *curr = Q->front;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

void deleteQueue(Queue *Q) {
    if (!Q) return;

    Node *curr = Q->front;
    Node *temp = NULL;
    while (curr) {
        temp = curr;
        curr = curr->next;
        delete temp;
        temp = NULL;
    }
    delete Q;
}

void print(Queue *Q) {
    if (!Q) return;
    Node *curr = Q->front;
    while (curr) {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}


int main() {
    cout<<"Implementing Queue using Linked List\n";
    Queue *Q = create();
    cout<<"Inserting few numbers\n";
    enqueue(Q, 1);
    enqueue(Q, 2);
    enqueue(Q, 3);
    enqueue(Q, 4);
    print(Q);
    cout<<"Size of the Queue: "<<size(Q)<<endl;
    cout<<"Deleting first two\n";
    cout<<dequeue(Q)<<endl;
    cout<<dequeue(Q)<<endl;
    cout<<"Size of the Queue: "<<size(Q)<<endl;
    print(Q);
    cout<<"Deleting next two\n";
    cout<<dequeue(Q)<<endl;
    cout<<dequeue(Q)<<endl;
    cout<<"Size of the Queue: "<<size(Q)<<endl;
    print(Q);

    deleteQueue(Q);
    return 0;
}



