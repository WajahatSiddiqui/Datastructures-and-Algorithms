#include<iostream>
using namespace std;

struct Stack {
    int top, size;
    int *array;
};

Stack* createStack(int size) {
    Stack *stack = new Stack();
    if (!stack) return NULL;

    stack->top = -1;
    stack->size = size;

    stack->array = new int[stack->size];
    if (!stack->array) return NULL;

    return stack;
}

bool isEmpty(Stack *stack) {
    return stack && stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack && (stack->top + 1 == stack->size);
}

void push(Stack *stack, int data) {
    if (isFull(stack)) return;

    stack->array[++stack->top] = data;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) return -1;

    int data = stack->array[stack->top];
    stack->top--;
    return data;
}

int top(Stack *stack) {
    return stack->array[stack->top];
}

void print(Stack *stack) {
    for (int i = 0; i <= stack->top; i++)
        cout<<stack->array[i]<<" ";
    cout<<endl;
}

/**
 * return remaining size of stack
 */
size_t size(Stack *stack) {
    return isEmpty(stack) ? 0 : (stack->size - (stack->top + 1));
}

void deleteStack(Stack *stack) {
    if (isEmpty(stack) && !stack->array) return;

    delete [] stack->array;
    delete stack;
}


int main() {

    Stack *stack = createStack(10);
    cout<<"Pushing 1~11 \n";
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    push(stack, 7);
    push(stack, 8);
    push(stack, 9);
    push(stack, 10);
    push(stack, 11);

    print(stack);

    cout<<"Size of stack: "<<size(stack)<<endl;

    int del = 5;
    cout<<"Popping 5 elements\n";
    while (del--) {
        cout<<pop(stack)<<" ";
    }
    cout<<endl;
    cout<<"top: "<<top(stack)<<endl;
    cout<<"Size of stack: "<<size(stack)<<endl;


    print(stack);
    del = 6;
    cout<<"Popping 6 elements\n";
    while (del--) {
        cout<<pop(stack)<<" ";
    }
    cout<<endl;

    cout<<"top: "<<top(stack)<<endl;

    cout<<"Size of stack: "<<size(stack)<<endl;

    deleteStack(stack);

    return 0;
}

