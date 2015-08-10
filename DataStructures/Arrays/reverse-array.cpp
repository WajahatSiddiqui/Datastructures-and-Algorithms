#include <iostream>
using namespace std;

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}


/**
 * Using Aux Array B
 * T(n) = O(n)
 * S(n) = O(n)
 */
void reverseArray(int A[],  int size) {
    int *B = new int[size];
    int l = 0, r = size-1;
    while (r >= 0) {
        B[l] = A[r];
        r--;
        l++;
    }
    printArray(B, size);
    delete [] B;
}

void swap(int &n1, int &n2) {
    int tmp = n1;
    n1 = n2;
    n2 = tmp;
}

/**
 * Swapping leftmost with rightmost
 * T(n) = O(n)
 * S(n) = 1
 */
void reverseArrayEfficiently(int A[], int size) {
    int l = 0, r = size-1, tmp = 0;

    while (l < r) {
        swap(A[l], A[r]);
        l++;
        r--;
    }
    printArray(A, size);
}

/**
 * Recursively swapping leftmost with the rightmost
 *
 * T(n) = O(n)
 * S(n) = O(n), stack
 */
void reverseArrayRecursive(int A[], int l, int r) {
    //cout<<"l = "<<l<<" r = "<<r<<endl;
    int tmp = 0;
    if (l >= r) return;
    swap(A[l], A[r]);
    reverseArrayRecursive(A, l+1, r-1);
}

int main() {
    int A[] = {17, -1, 10, 3, 2, 1};
    int size = sizeof(A)/sizeof(A[0]);

    printArray(A, size);
    // Normal Reverse Array using another array
    //reverseArray(A, size);
    
    // Reverse array using swapping left with right iteratively
    reverseArrayEfficiently(A, size);

    // Reverse array using swapping left with right recursively
    //reverseArrayRecursive(A, 0, size-1);
    //printArray(A, size);
    return 0;
}
