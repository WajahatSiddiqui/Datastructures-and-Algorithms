#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};


struct Stack {
    Node *top;
};

Stack* createStack() {
    Stack *stack = new Stack();
    if (!stack) return NULL;

    stack->top = NULL;
    return stack;
}

bool isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, int data) {
    Node *node = new Node();
    node->data = data;

    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) return -1;

    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    delete temp;
    temp = NULL;
    return data;
}

void deleteStack(Stack *stack) {
    if (!stack) return;

    Node *curr = stack->top;
    Node *prev = NULL;
    while (curr) {
        prev = curr;
        curr = curr->next;
        delete prev;
        prev = NULL;
    }
    delete curr;
}

int size(Stack *stack) {
    int count = 0;
    Node *curr = stack->top;
    while (curr) {
        curr = curr->next;
        count++;
    }
    return count;
}

void print(Stack *stack) {
    if (isEmpty(stack)) return;

    for (Node *curr = stack->top; curr != NULL; curr = curr->next)
        cout<<curr->data<<" ";
    cout<<endl;
}

int top(Stack *stack) {
    return stack->top->data;
}

int main() {
    Stack *stack = new Stack();
    cout<<"Pushing 1~5\n";
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    cout<<"size: "<<size(stack)<<endl;
    cout<<"Printing: \n";
    print(stack);

    cout<<"poping 4 elements\n";
    int del = 4;
    while (del--) {
        cout<<pop(stack)<<" ";
    }
    cout<<endl;
    cout<<"Printing: \n";
    print(stack);
    cout<<"size: "<<size(stack)<<endl;

    deleteStack(stack);
    return 0;
}

