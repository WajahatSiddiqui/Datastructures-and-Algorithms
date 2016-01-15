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

    return 0;
}
