#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};


class List {
    public:
        Node* getNode(int data);
        // Insert
        Node* append(Node *head, int data);
        Node* push(Node *head, int data);
        Node* insert(Node *head, int data, int position);

        // Delete
        Node* deletePosition(Node *head, int position);
        Node* deleteKey(Node *head, int key);
        Node* removeDuplicates(Node *head);

        // Operations
        Node* mergeSorted(Node *head1, Node *head2);
        Node* reverse(Node* head);
        Node* rotate(Node* head, int pos);
        int compare(Node *head1, Node *head2);
        int size(Node *head);
        bool detectLoop(Node *head);
        Node* detectAndRemoveLoop(Node *head);
        int findMergedNode(Node* headA, Node* headB);
        Node* swap(Node* head, int n1, int n2);
        Node* findMiddle(Node *head);

        // Display
        void print(Node *head);
        void printEnd(Node *head);
};

#endif // __LIST_H__
