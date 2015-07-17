#include <iostream>
#include <queue>
using namespace std;

struct stack {
    queue<int> q1, q2;
};

void push (stack *s, int data) {
    if (s->q1.empty())
        s->q2.push(data);
    else
        s->q1.push(data);
}

int pop(stack *s) {
    int size, front;
    if (s->q1.empty()) {
        // Enqueue n-1 elements from q2 -> q1
        // return nth element from q2
        size = s->q2.size();
        for (int i = 0;  i < size-1; i++) {
            s->q1.push(s->q2.front());
            s->q2.pop();
        }
        front = s->q2.front();
        s->q2.pop();
    } else {
        // Enqueue n-1 elements from q1 -> q2
        // return nth element from q1
        size = s->q1.size();
        for (int i = 0; i < size-1; i++) {
            s->q2.push(s->q1.front());
            s->q1.pop();
        }
        front = s->q1.front();
        s->q1.pop();
    }
    return front;

}

int main() {
    stack *s = new stack;
    cout<<"Pushing 1,2,3,4 \n";
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    cout<<"Popping out first two \n";
    cout<<pop(s)<<" ";
    cout<<pop(s)<<endl;
    cout<<"Pushing 10,11 \n";
    push(s, 10);
    push(s, 11);
    cout<<"Popping out next four\n";
    cout<<pop(s)<<" ";
    cout<<pop(s)<<" ";
    cout<<pop(s)<<" ";
    cout<<pop(s)<<endl;

    delete s;
    return 0;
}
