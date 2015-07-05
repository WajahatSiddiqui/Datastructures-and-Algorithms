/**
 * Implement various operations on LinkedList
 */
#include <iostream>
#include "List.h"
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
Node* List::newNode(int data) {
    Node *node = create();
    if (!node) return NULL;

    node->data = data;
    node->next = NULL;
}

/**
 * Inserts given data at the end of list
 */
Node* List::insert(Node *head, int data) {
    Node *newNode = newNode(data);
    if (!head) {
        head = newNode;
    } else {
        Node *curr = head, *prev = NULL;
        while (curr) {
            prev = curr;
            curr = curr->next;          
        }
        prev->next = newNode;
    }
    return head;
}

/**
 * Inserts given data at a given position
 * in the list
 */
Node* List::insert(Node *head, int data, int position) {
    Node *newNode = newNode(data);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *curr = head, *prev = NULL;
        while (curr && position--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
    return head;
}


/**
 * Push given data at the top of the list
 */
Node* List::push(Node *head, int data) {
   Node *newNode = newNode(data);
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

/**
 * Deletes a node for the given data
 * in the list
 */
Node* List::deleteNode(Node *head, int data) {
    if (!head) return NULL;
    Node *curr = head, *prev = NULL;
    if (position == 0) {
        prev = curr;
        curr = curr->next;
        head = curr;
        if (!prev->next)
            prev->next = NULL;
        free(prev);
        prev = NULL;
    } else {
        while (curr && position--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
        curr = NULL;
    }
    return head;
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
bool List::detectLoop(Node *list) {
}

/**
 * Merge sorted given two sorted lists and
 * returns the list in the sorted order
 * list1: 1->2->3->NULL
 * list2: 4->5->6->NULL
 * returns 1->2->3->4->5->6->NULL
 */
Node* List::mergeSorted(Node *list1, Node *list2) {
    if (!list1 && !list2) return NULL;
    if (!list1) return list2;
    if (!list2) return list1;
    int data = 0;
    Node *mergeList = NULL, *curr1 = list1, *currB = list2;
    while (curr1 || currB) {
        if (curr1 && currB) {
            if (curr1->data <= currB->data) {
                data = curr1->data;
                curr1 = curr1->next;
            } else {
                data = currB->data;
                currB = currB->next;
            }
            mergeList = insert(mergeList, data);
        } else if (curr1 == NULL) {            
            while (currB) {
                mergeList = insert(mergeList, currB->data);
                currB = currB->next;
            }
        } else if (currB == NULL) {
            while (curr1) {
                mergeList = insert(mergeList, curr1->data);
                curr1 = curr1->next;
            }
                
        }
    }
    return mergeList;
}

/**
 * Merge two lists in the following way
 * list1: a1->a2->a3-> .. ->an->NULL (n elements)
 * list2: b1->b2->b3-> .. ->bm->NULL (m elements)
 * returns a1->b1->a2->b2-> .. -> an->bm->am+1->an->NULL if (n >= m)
 * returns a1->b1->a2->b2-> .. -> an->bn->bn+1->am->NULL if (m >= n)
 */
Node* List::mergeList(Node *list1, Node *list2) {
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
Node* List::findIntersectNode(Node *list1, Node *list2) {
}


/**
 * Reverse a given list and returns the reversed
 * linked list
 */
Node* List::reverse(Node *list) {
    if (!head) return NULL;
    Node *curr = head, *prev = NULL, *rev = NULL;
    while (curr) {
        rev = curr->next;
        curr->next = prev;
        prev = curr;
        curr = rev;
    }
    head = prev;
    return head;
}

/**
 * Find the kth node from the begining
 */
Node* List::find(Node *list, int k) {
}

/**
 * Find the kth node from the end
 */
Node* List::findEnd(Node *list, int k) {
}

/**
 * Find n/kth element in a given list
 * where n is the size of the list
 */
Node* List::findFractionalNode(Node *list, int k) {
}

/**
 * find sqrt(nth) node where n is the 
 * number of elements in a given list
 */
Node* List::findSqrtNode(Node *list) {
}

/**
 * Prints the list from head.
 */
void List::print(Node *list) {
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
void List::printFromEnd(Node *list) {
    if (!list) return;
    printFromEnd(list->next);
    cout<<list->data<<" ";
}

/**
 * Check if given list length is even or odd
 */
bool List::isListEven(Node *list) {
}

/**
 * Reverse the linked list in pairs
 * list: 1->2->3->4->NULL
 * return 2->1->4->3->NULL
 */
Node* List::reverseInPairs(Node *list) {
}

/**
 * Sorts the element in the list
 * list: 10->8->0->1->3->NULL
 * returns 0->1->3->8->10->NULL
 */
Node* List::sort(Node *list) {
}

/**
 * Check if the given list is palidrome
 * list: 1->2->3->2->1->NULL
 * returns true
 * list: 1->2->3->1->NULL
 * returns false
 */
bool List::isPalidrome(Node *list) {
}

/**
 * Finds the middle Node of the given list
 */
Node* List::findMiddle(Node *list) {
}


/**
 * Clone a linked list with a random pointer
 */
Node* List::clone(Node *list) {
}

/**
 * Given a linked list, finds the last element
 * from the begining such that n%k = 0 where
 * n is the number of elements in the given list
 * and k is a given integer constant
 * Eg: n = 19, k = 3 => n%k = 4 the node return will be 
 *
 */
Node* List::findModularNode(Node *list, int k) {
}

/**
 * Compare two given linked list 
 * returns 1 if list1 == list2 else 0
 */
int List::compare(Node *list1, Node *list2) {
    if (!list1 || !list2) return 0;
    Node *curr1 = list1, *curr2 = list2;
    int count1 = 0, count2 = 0;
    while (curr1 != NULL || curr2 != NULL) {
        if (curr1 != NULL && curr2 != NULL 
            && curr1->data != curr2->data) return 0;
        if (curr1) {
            curr1 = curr1->next;
            count1++;
        }
        if (curr2) {
            curr2 = curr2->next;
            count2++;
        }
    }
    return (count1 == count2);
}

int List::getNode(Node *head, int positionFromTail) {
    if (!head) return 0;
    Node *curr = head, *prev = head;
    int len = 0;
    while (curr) {
        len++;
        curr = curr->next;
    }
    int pos = len - positionFromTail;
    curr = head;
    while (curr && pos--) {
        prev = curr;
        curr = curr->next;
    }
    return prev->data;
}
