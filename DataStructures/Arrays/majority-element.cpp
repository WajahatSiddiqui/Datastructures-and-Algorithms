/**
 * Identify Majority Element in an Array
 * An element which apprears atmost n/2 times in an array
 * is known as Majority Element
 *
 * I/P: 3 2 2 3 2 2 2 2
 * O/P: 2
 *
 * I/P: 3 3 2 2 4 4
 * O/P: None
 */
#include <iostream>
#include <string.h>
using namespace std;

void findMajorityElement(int A[], int size) {
    int *count = new int[size];
    if (!count) return;
    memset(count, 0, sizeof(count));

    for (int i = 0; i < size; i++)
        count[A[i]]++;
    int majority = size/2;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (count[i] >= majority) {
            cout<<"Majority element: "<<i<<endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout<<"Majority Element: None"<<endl;
    delete [] count;
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int main() {
    int A[] = {3, 2, 2, 4, 2, 2, 3, 2, 2, 3, 3, 3, 3, 3};
    int size = sizeof(A)/sizeof(A[0]);

    printArray(A, size);
    findMajorityElement(A, size);

    int B[] = {3, 3, 2, 2, 4, 4};
    size = sizeof(B)/sizeof(B[0]);
    printArray(B, size);
    findMajorityElement(B, size);

    return 0;
}
