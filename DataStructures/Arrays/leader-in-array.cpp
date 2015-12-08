/**
 * Print Leaders in the array
 * A number is a leader if it is greater that all the elements
 * on its right side
 * Right most element is always a leader
 */
#include <iostream>
using namespace std;

/**
 * 1) Take a number and test if it
 * greater than all the numbers on right side
 * 2) if the test counter reaches size, then it is
 * leader, print it, else if any one is less than
 * this number then break immediately.
 * T(n) = O(n^2)
 */
void printLeader(int A[], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i+1; j < size; j++) {
            if (A[i] < A[j]) break;
        }
        if (j == size)
            cout<<A[i]<<" ";
    }
    cout<<endl;
}

/**
 * Use single for loop
 * 1) Start from the right most 
 * 2) compare with the next right 
 * 3) if it is greater then it is leader
 * T(n) = O(n)
 */
void printLeaderEfficiently(int A[], int size) {
    int nextRight = 0, i;
    for (i = size-1; i != 0; i--) {
        if (i < size-1) { // in between
            nextRight = A[i+1];
            if (A[i] > nextRight)
                cout<<A[i]<<" ";
        } else if (i == size-1) {//right most
            cout<<A[i]<<" ";
        }
    }
    if (i == 0 && A[i] > A[i+1]) //left most
            cout<<A[i]<<" ";
    cout<<endl;
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int main() {
    int A[] = {21, 23, 22, 15, 17, 18, 5, 3, 4, 1};
    int size = sizeof(A) / sizeof(A[0]);

    printArray(A, size);
    cout<<"Leaders: ";
    printLeader(A, size);
    cout<<"Leader Efficient: ";
    printLeaderEfficiently(A, size);

    return 0;
}
