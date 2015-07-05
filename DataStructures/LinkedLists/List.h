#ifndef __LIST_H__
#define __LIST_H__

struct Node {
    int data;
    Node *next;
};


class List {
    public:
        Node* newNode(int data);
        Node* insert(Node *head, int data);
        Node* insert(Node *head, int data, int position);
        Node* push(Node *head, int data);
        Node* deleteNode(Node *head, int data);

        Node* mergeSorted(Node *list1, Node *list2);
        Node* mergeList(Node *list1, Node *list2);
        Node* findIntersectNode(Node *list1, Node *list2);
        Node* reverse(Node *list);
        Node* find(Node *list, int k);
        Node* findEnd(Node *list, int k);
        Node* findFractionalNode(Node *list, int k);
        Node* findSqrtNode(Node *list);
        Node* reverseInPairs(Node *list);
        Node* sort(Node *list);
        Node* findMiddle(Node *list);
        Node* clone(Node *list);
        Node* findModularNode(Node *list);        

        void print(Node *list);
        void printEnd(Node *list);
        
        bool detectLoop(Node *list);
        bool isEven(Node *list);
        bool isPalidrome(Node *list);
};

#endif // __LIST_H__
