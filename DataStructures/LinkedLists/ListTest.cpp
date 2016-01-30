#include "List.h"

int main() {
    Node *head = NULL;
    List *list = new List();
    cout<<"Appending in list1: ";
    head = list->append(head, 1);
    head = list->append(head, 2);
    head = list->append(head, 10);

    list->print(head);

    cout<<"Appending in list2: ";
    Node *aHead = NULL;
    aHead = list->append(aHead, -1);
    aHead = list->append(aHead, 4);
    aHead = list->append(aHead, 7);
    list->print(aHead);

    cout<<"mergeSorted: ";
    Node *merged = list->mergeSorted(head, aHead);
    list->print(merged);

    cout<<"reverse: ";
    Node *rev = list->reverse(merged);
    list->print(rev);

    Node *head1 = NULL;
    head1 = list->append(head1, 1);
    head1 = list->append(head1, 2);
    head1 = list->append(head1, 10);

    cout<<"comparing two equal list: ";
    cout<<list->compare(head, head1)<<endl;

    cout<<"deleting with position = 2 in reverse list\n";
    list->deletePosition(rev, 2);
    list->print(rev);

    cout<<"deleting with key = -1 in reverse list\n";
    list->deleteKey(rev, -1);
    list->print(rev);

    Node *rotateHead = NULL;
    rotateHead = list->append(rotateHead, 1);
    rotateHead = list->append(rotateHead, 2);
    rotateHead = list->append(rotateHead, 3);
    rotateHead = list->append(rotateHead, 4);
    rotateHead = list->append(rotateHead, 5);
    cout<<"Rotating below list from pos = 3\n";
    list->print(rotateHead);
    Node *rotated = list->rotate(rotateHead, 3);
    list->print(rotated);

    cout<<"Removing dupicates in 1->2->2->3->3->3->3->4\n";
    Node *duplicate = NULL;
    duplicate = list->append(duplicate, 1);
    duplicate = list->append(duplicate, 2);
    duplicate = list->append(duplicate, 2);
    duplicate = list->append(duplicate, 3);
    duplicate = list->append(duplicate, 3);
    duplicate = list->append(duplicate, 3);
    duplicate = list->append(duplicate, 3);
    duplicate = list->append(duplicate, 4);
    list->removeDuplicates(duplicate);
    list->print(duplicate);
    return 0;
}
