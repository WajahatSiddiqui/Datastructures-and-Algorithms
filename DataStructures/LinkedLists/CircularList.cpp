/**
 * Implement Circular Linked List
 */
 #include <iostream>
 using namespace std;

 struct Node {
 	int data;
 	Node *next;
 };

/**
 * Prints the list from any given node
 * This node will be considered as the first node
 */
void print(Node *first) {
	if (!first) return;
	Node *curr = first;
	do {
		cout<<curr->data<<" ";
		curr = curr->next;
	} while(curr != first);
	cout<<endl;
}

/**
 * Pushes a node containing data
 * at the first position and updates
 * next link to the head.
 */
void push(Node **head, int data) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = *head;
	Node *curr = *head;
	if (*head) {
		while(curr->next != *head) curr = curr->next;
		curr->next = newNode;
	} else
		newNode->next = newNode;
	*head = newNode;
}

 int main() {
 	Node *head = NULL;
 	push(&head, 1);
 	push(&head, 2);
 	push(&head, 3);
 	print(head);
 	print(head->next);
 	print(head->next->next);
 	return 0;
 }