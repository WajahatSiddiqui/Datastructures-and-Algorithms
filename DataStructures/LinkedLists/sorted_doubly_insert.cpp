#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *prev, *next;
};

Node* sorted_insert(Node* head, int data) {
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if (head == NULL) return node;
    else {
        // first node
        if (data < head->data) {
            node->next = head;
            head->prev = node;
            head = node;
        } else {
            Node *curr = head;
            while (curr->next) {
                if (data > curr->data && data < curr->next->data) break;
                curr = curr->next;
            }
            // middle
            if (curr->next) {
                Node *next = curr->next;
                curr->next = node;
                node->prev = curr;
                node->next = next;
                next->prev = node;
            } else { //last
                curr->next = node;
                node->prev = curr;
            }
        }
    }
    return head;
}

void print(Node *head) {
	Node *curr = head;
	while (curr) {
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

int main() {
	Node *head = NULL;
	head = sorted_insert(head, 2);
	head = sorted_insert(head, 4);
	head = sorted_insert(head, 6);
	head = sorted_insert(head, 5);
	head = sorted_insert(head, 1);
	print(head);
	return 0;
}