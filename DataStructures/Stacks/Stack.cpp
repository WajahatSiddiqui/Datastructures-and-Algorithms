#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int d) : data(d) { next = NULL; }
};

class Stack {
    Node *t; // top
public:
    Stack() : t(NULL) {}
    ~Stack() {
        if (isEmpty()) return;

        Node *curr = t;
        Node *prev = NULL;
        while (curr) {
            prev = curr;
            curr = curr->next;
            delete prev;
            prev = NULL;
        }
        delete curr;
    }

    bool isEmpty() { return t == NULL; }

    void push(int data);
    void pop();
    Node* top() { return t; }
    int size();
    void print();
};


void Stack::push(int data) {
    Node *node = new Node(data);

    node->next = t;
    t = node;
}

void Stack::pop() {
    if (isEmpty()) return;

    Node *temp = t;
    t = t->next;
    delete temp;
    temp = NULL;
}

int Stack::size() {
    int count = 0;
    Node *curr = t;
    while (curr) {
        curr = curr->next;
        count++;
    }
    return count;
}

void Stack::print() {
    if (isEmpty()) return;

    for (Node *curr = t; curr != NULL; curr = curr->next)
        cout<<curr->data<<" ";
    cout<<endl;
}

int main() {
    Stack *s = new Stack();
    cout<<"Pushing 1~5\n";
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);

    cout<<"size: "<<s->size()<<endl;
    cout<<"Printing: \n";
    s->print();
    cout<<"top = "<<s->top()->data<<endl;
    int del = 3;
    cout<<"poping "<<del<<" elements";
    while (del--) {
        s->pop();
    }
    cout<<endl;
    cout<<"Printing: ";
    s->print();
    cout<<"size: "<<s->size()<<endl;

    delete s;
    return 0;
}

