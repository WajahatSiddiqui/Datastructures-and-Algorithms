/**
 * Implement Queue using LinkedList
 */
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int d) : data(d) { next = NULL; }
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
    int size();

    void enqueue(int d);
    void dequeue();
    void print();
};

void Queue::enqueue(int d) {
    Node *n = new Node(d);
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

int Queue::size() {
    if (isEmpty()) return 0;
    int count = 0;
    Node *curr = fr;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

void Queue::print() {
    if (isEmpty()) return;
    Node *curr = fr;
    while (curr) {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}


int main() {
    cout<<"Implementing Queue using Linked List\n";
    Queue *q = new Queue();
    cout<<"Inserting few numbers\n";
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->print();
    cout<<"Size of the Queue: "<<q->size()<<endl;
    cout<<"front = "<<q->front()->data<<endl
        <<"rear = "<<q->rear()->data<<endl;
    cout<<"Deleting first two\n";
    q->dequeue();
    q->dequeue();
    cout<<"Size of the Queue: "<<q->size()<<endl;
    q->print();
    cout<<"Deleting next two\n";
    q->dequeue();
    q->dequeue();
    cout<<"Size of the Queue: "<<q->size()<<endl;
    q->print();

    delete q;
    return 0;
}



