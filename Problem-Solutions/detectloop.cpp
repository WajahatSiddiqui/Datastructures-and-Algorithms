#include <iostream>
using namespace std;

struct node {
    int data;
    node* link;
};

static void push(node **head_ref, int data) {
    node *n = new node();
    n->data = data;
    n->link = *head_ref;
    *head_ref = n;
}

bool detectLoop(node **head_ref) {
    node *slowp = *head_ref;
    node *fastp = *head_ref;
    while (slowp && fastp && fastp->link) {
        slowp = slowp->link;
        fastp = fastp->link->link;
        if (slowp == fastp)
            return true;
    }
    return false;
}


static void print(node **head_ref) {
    node *temp = *head_ref;
    while (temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}

int main() {
    node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    print(&head);
    head->link->link->link->link = head->link->link;
    if (detectLoop(&head))
        cout<<"Loop detected\n";
    else
        cout<<"there is no loop\n";
    return 0;
}
