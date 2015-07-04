/**
 * Implement various operations on LinkedList
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

/**
 * Create a Node for LinkedList
 */
Node* create() {
    Node *node = new Node();
    if (!node) {
        cout<<"Error could not create node\n";
    }
    return node;
}

/**
 * Creates a new node given data
 */
Node* newNode(int data) {
    Node *node = create();
    if (!node) return NULL;

    node->data = data;
    node->next = NULL;
}

/**
 * Inserts given data at the end of list
 */
Node* insert(int data) {
}

/**
 * Inserts given data at a given position
 * in the list
 */
Node* insert(int data, int position) {
}


/**
 * Push given data at the top of the list
 */
Node* push(int data) {
}

/**
 * Deletes a node for the given data
 * in the list
 */
Node* deleteNode(Node *list, int data) {
}



/**
 * Detects if loop exists in the given
 * List. Uses Floyds Cycle Finding Algorithm.
 *
 * list: 1->2->3->4 returns true
 *             |__|
 *
 * list: 1->2->NULL return false
 */
bool detectLoop(Node *list) {
}

/**
 * Merge sorted given two sorted lists and
 * returns the list in the sorted order
 * list1: 1->2->3->NULL
 * list2: 4->5->6->NULL
 * returns 1->2->3->4->5->6->NULL
 */
Node* mergeSorted(Node *list1, Node *list2) {
}

/**
 * Merge two lists in the following way
 * list1: a1->a2->a3-> .. ->an->NULL (n elements)
 * list2: b1->b2->b3-> .. ->bm->NULL (m elements)
 * returns a1->b1->a2->b2-> .. -> an->bm->am+1->an->NULL if (n >= m)
 * returns a1->b1->a2->b2-> .. -> an->bn->bn+1->am->NULL if (m >= n)
 */
Node* mergeList(Node *list1, Node *list2) {
}

/**
 * Finds the intersection point of the two
 * given list and returns the node where the
 * intersection exists.
 * 1->2->3--\
 *          \->6->7->NULL
 *          /
 * 4->5---/
 * return Node at 6
 */
Node* findIntersectNode(Node *list1, Node *list2) {
}


/**
 * Reverse a given list and returns the reversed
 * linked list
 */
Node* reverse(Node *list) {
}

/**
 * Find the kth node from the begining
 */
Node* find(Node *list, int k) {
}

/**
 * Find the kth node from the end
 */
Node* findEnd(Node *list, int k) {
}

/**
 * Find n/kth element in a given list
 * where n is the size of the list
 */
Node* findFractionalNode(Node *list, int k) {
}

/**
 * find sqrt(nth) node where n is the 
 * number of elements in a given list
 */
Node* findSqrtNode(Node *list) {
}

/**
 * Prints the list from head.
 */
void print(Node *list) {
    if (!list) return;
    Node *curr = list;
    while (curr) {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

/**
 * Prints the list from the end.
 */
void printFromEnd(Node *list) {
    if (!list) return;
    printFromEnd(list->next);
    cout<<list->data<<" ";
}

/**
 * Check if given list is even or odd
 */
bool isListEven(Node *list) {
}

/**
 * Reverse the linked list in pairs
 * list: 1->2->3->4->NULL
 * return 2->1->4->3->NULL
 */
Node* reverseInPairs(Node *list) {
}

/**
 * Sorts the element in the list
 * list: 10->8->0->1->3->NULL
 * returns 0->1->3->8->10->NULL
 */
Node* sort(Node *list) {
}

/**
 * Check if the given list is palidrome
 * list: 1->2->3->2->1->NULL
 * returns true
 * list: 1->2->3->1->NULL
 * returns false
 */
bool isPalidrome(Node *list) {
}

/**
 * Finds the middle Node of the given list
 */
Node* findMiddle(Node *list) {
}


/**
 * Clone a linked list with a random pointer
 */
Node* clone(Node *list) {
}

/**
 * Given a linked list, finds the last element
 * from the begining such that n%k = 0 where
 * n is the number of elements in the given list
 * and k is a given integer constant
 * Eg: n = 19, k = 3 => n%k = 4 the node return will be 
 *
 */
Node* findModularNode(Node *list, int k) {
}

