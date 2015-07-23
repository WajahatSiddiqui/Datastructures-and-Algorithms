/**
 * Given two linked list which are already sorted
 * Merge the two list in sorted order.
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* link;
};

struct Node* newNode(int data) {
    struct Node *newN = new struct Node();
    newN->data = data;
    newN->link = NULL;
    return newN;
}

void insert(struct Node **head, int data) {
    struct Node *newN = newNode(data);
    if (!newN) return;
    if (*head == NULL)
        *head = newN;
    else {
        struct Node *curr = *head;
        while(curr->link) {
            curr = curr->link;
        }
        curr->link = newN;
    }
}

struct Node* sortedMerge(struct Node* list1, struct Node* list2) {
    if (!list1 && !list2) return NULL;
    if (!list1) return list2;
    if (!list2) return list1;

    struct Node *t1 = list1, *t2 = list2, *newList = NULL;
    int data = 0;
    while (t1 != NULL || t2 != NULL) {
        if (t1 != NULL && t2 != NULL) {
            if (t1->data >= t2->data) {
                data = t2->data;
                t2 = t2->link;
            }
            else {
                data = t1->data;
                t1 = t1->link;
            }
            insert(&newList, data);
        }
        if (t1 == NULL) {
            while (t2) {
                insert(&newList, t2->data);
                t2 = t2->link;
            }
        }
        else if (t2 == NULL) {
            while (t1) {
                insert(&newList, t1->data);
                t1 = t1->link;
            }
        }
    }
    return newList;
}

void printList(struct Node* list) {
    if (!list) return;
    struct Node *curr = list;
    while (curr) {
        cout<<curr->data<<" ";
        curr = curr->link;
    }
    cout<<endl;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    insert(&list1, 10);
    insert(&list1, 20);
    insert(&list1, 30);
    insert(&list1, 30);
    insert(&list1, 30);
    insert(&list1, 30);
    insert(&list1, 30);
    insert(&list1, 30);
    cout<<"List1: ";
    printList(list1);
    insert(&list2, -1);
    insert(&list2, 20);
    insert(&list2, 40);
    insert(&list2, 40);
    insert(&list2, 40);
    insert(&list2, 40);
    insert(&list2, 40);
    insert(&list2, 40);
    cout<<"List2: ";
    printList(list2);

    cout<<"SortedMergeList: ";
    printList(sortedMerge(list1, list2));
    return 0;
}
