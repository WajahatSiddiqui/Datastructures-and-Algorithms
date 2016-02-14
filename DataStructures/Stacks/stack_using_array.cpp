#include <iostream>
#include <stdlib.h>
using namespace std;

class Stack {
private:
    int m_top, m_size;
    int *m_array;
public:
    Stack(int _size) : m_size(_size) {
        m_top = -1;
        m_array = new int[m_size];
        if (!m_array) {
            cout<<"Error can't initialize stack\n";
            exit(0);
        }    
    }

    ~Stack() {
        if (isEmpty() && !m_array) return;
        delete [] m_array;
    }

    bool isEmpty() {
        return m_top == -1;
    }

    bool isFull() {
        return (m_top + 1 == m_size);
    }

    void push(int data) {
        if (isFull()) return; // overflow
        m_array[++m_top] = data;
    }

    int pop() {
        if (isEmpty()) return -1; // underflow

        int data = m_array[m_top];
        m_top--;
        return data;
    }

    int top() {
        if (isEmpty()) return -1;
        return m_array[m_top];
    }

    void print() {
        for (int i = 0; i <= m_top; i++)
            cout<<m_array[i]<<" ";
        cout<<endl;
    }
    /**
     * return remaining m_size of stack
     */
    size_t size() {
        return m_top == -1 ? 0 : (m_size -1 - m_top);
    }
};


int main() {

    Stack *stack = new Stack(10);
    cout<<"Pushing 1~11 \n";
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->push(6);
    stack->push(7);
    stack->push(8);
    stack->push(9);
    stack->push(10);
    stack->push(11);
    cout<<"top: "<<stack->top()<<endl;
    stack->print();

    cout<<"size of remaining stack: "<<stack->size()<<endl;

    int del = 5;
    cout<<"Popping 5 elements\n";
    while (del--) {
        cout<<stack->pop()<<" ";
    }
    cout<<endl;
    stack->print();
    cout<<"top: "<<stack->top()<<endl;
    cout<<"size of remaining stack: "<<stack->size()<<endl;

   stack->print();
    del = 6;
    cout<<"Popping 6 elements\n";
    while (del--) {
        cout<<stack->pop()<<" ";
    }
    cout<<endl;

    cout<<"top: "<<stack->top()<<endl;

    cout<<"size of remaining stack: "<<stack->size()<<endl;
    stack->pop();
    stack->pop();
    cout<<"top: "<<stack->top()<<endl;
    delete stack;

    return 0;
}