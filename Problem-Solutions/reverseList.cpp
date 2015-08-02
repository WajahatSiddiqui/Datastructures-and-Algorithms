#include <iostream>
using namespace std;

struct node {
    int m_data;
    node *m_link;
    node(int data) {
        m_data = data;
        m_link = NULL;
    }
};

static void insert(node **head, int data) {
    node *newNode = new node(data);
    if (!newNode) {
        cout<<"Error, Insufficient Memory\n";
        return;
    }
    if (*head == NULL) {
        *head = newNode;
        return;
    } else {
        node *curr = *head;
        while(curr->m_link != NULL) {
           curr = curr->m_link;
        }
        curr->m_link = newNode;
    }
}

static void push(node **head, int data) {
    node *newNode = new node(data);
    if (!newNode) {
        cout<<"Error, Insufficient memory\n";
        return;
    }
    newNode->m_link = *head;
    *head = newNode;
}

static void print(node **head) {
    node *curr = *head;
    while(curr != NULL) {
        cout<<curr->m_data<<" ";
        curr = curr->m_link;
    }
}

static void reverse(node **head) {
    node *prev, *curr, *next;
    prev = NULL;
    curr = *head;
    while (curr != NULL) {
        next = curr->m_link;
        curr->m_link = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    /*push(&head, 1);
    push(&head, 2);
    push(&head, 3);*/
    
    print(&head);
    reverse(&head);
    cout<<"\nAfter reverse: ";
    print(&head);
 
    return 0;
}

