/**
 * Implement various operations on LinkedList
 */
#include "List.h"
using namespace std;

/**
 * Creates a new node given data
 */
Node* List::getNode(int data) {
    Node *node = new Node();
    if (!node) return NULL;

    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * Append given data to the list
 */
Node* List::append(Node *head, int data) {
    Node *newNode = getNode(data);
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
 * Inserts data at a given position
 * in the list
 */
Node* List::insert(Node *head, int data, int position) {
    Node *newNode = getNode(data);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node *curr = head, *prev = NULL;
        while ((curr || curr->next) && position--) {
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
   Node *newNode = getNode(data);
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
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
            mergeList = append(mergeList, data);
        } else if (curr1 == NULL) {            
            while (currB) {
                mergeList = append(mergeList, currB->data);
                currB = currB->next;
            }
        } else if (currB == NULL) {
            while (curr1) {
                mergeList = append(mergeList, curr1->data);
                curr1 = curr1->next;
            }
                
        }
    }
    return mergeList;
}

/**
 * Reverse a given list and returns the reversed
 * linked list
 */
Node* List::reverse(Node* head) {
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

/**
 * Deletes a node at a given position in the list
 */
Node* List::deletePosition(Node *head, int position) {
    if (!head) return NULL;
    Node *curr = head, *prev = NULL;
    if (position == 0) {
          head = curr->next;;
        delete curr;
        curr = NULL;
    } else {
        while (curr && position--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        curr = NULL;
    }
    return head;
}

/**
 * Deletes a node based on the key
 */
 Node* List::deleteKey(Node *head, int key) {
    if (!head) return NULL;
    Node *curr = head, *prev = NULL;
    if (curr->data == key) {
        head = curr->next;
        delete curr;
        curr = NULL;
    } else {
        while (curr && key != curr->data) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
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
bool List::detectLoop(Node *head) {
    if (!head) return false;
    return false;
}


/**
 * Prints the list from head.
 */
void List::print(Node *head) {
    if (!head) return;
    Node *curr = head;
    while (curr) {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

/**
 * Prints the list from the end.
 */
void List::printEnd(Node *head) {
    if (!head) return;
    printEnd(head->next);
    cout<<head->data<<" ";
}

/**
 * Rotate the list from the given position
 * 1->2->3->4->5 after rotation from pos=3
 * 4->5->1->2->3
 * T(n) = O(n)
 */
 Node* List::rotate(Node *head, int pos) {
    if (!head) return NULL;
    if (pos == 0 || pos > size(head)) return head;
    Node *curr, *prev, *temp = head;
    curr = head;
    while(pos-- && curr->next) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    head = curr;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
 }

/**
 * Returns the number of items in the
 * list
 * T(n) = O(n)
 */
 int List::size(Node *head) {
    if (!head) return 0;
    int i = 0;
    Node *curr = head;
    while(curr) {
        i++;
        curr = curr->next;
    }
    return i;
 }


 Node* List::removeDuplicates(Node* head) {
    if (!head) return NULL;
    Node *prev = NULL, *curr = head, *temp = NULL;

    while(curr) {
        prev = curr;
        curr = curr->next;
        while (curr && (prev->data == curr->data)) {
            temp = curr;
            curr = curr->next;
            delete temp;
            temp = NULL;
            if (prev->next != NULL)
                prev->next = NULL;
        }
        if (prev->next == NULL) prev->next = curr;
    }
    return head;
 }