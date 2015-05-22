//http://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
#include <iostream>
#include <stdlib.h>
using namespace std;
struct ListNode {
    int data;
    struct ListNode* next;
};

static struct ListNode* getNode(int data) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode*));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

static void push(struct ListNode **head_ref, int data) {
    struct ListNode *newNode = getNode(data);
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

static struct ListNode* addList(struct ListNode* first, struct ListNode* second) {
    struct ListNode *prev, *temp, *res = NULL;
    int sum = 0, carry = 0;
    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = getNode(sum);
        if (res == NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;
        if (first) first = first->next;
        if (second) second = second->next;
    }
    if (carry > 0) {
        temp = getNode(carry);
        prev->next = temp;
    }
    return res;
}

static void print(struct ListNode *list) {
    while (list != NULL) {
        cout<<list->data<<" ";
        list = list->next;
    }
    cout<<endl;
}

int main() {
    struct ListNode *first = NULL, *second = NULL;
    // 3->9 represented: 93
    push(&first, 9);
    push(&first, 3);

    // 7->1 represented: 17
    push(&second, 1);
    push(&second, 7);
    
    print(first);
    print(second);
    print(addList(first, second));

    return 0;
}
