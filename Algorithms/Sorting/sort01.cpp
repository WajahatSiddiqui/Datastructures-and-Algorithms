/**
 * Segregating 0 and 1 in the given array of 0 & 1 in one pass
 * http://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
 */
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = *a;
}

// T(n) = O(n)
// S(n) = O(n)
void sort01(int A[], int size) {
    int left = 0;
    int right = size-1;
    while (left < right) {
        if (A[left] == 0 && left < right)
            left++;
        if (A[right] == 1 && left < right)
            right--;
        if (A[left] == 1 && A[right] == 0) {
            A[left++] = 0;
            A[right--] = 1;
        }
    } 
}


void print(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout<<A[i]<<" ";
    }
}

int main() {
    int A[] = {0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0};
    int size = sizeof(A)/sizeof(int);
    cout<<"Size = "<<size<<endl;
    cout<<"Input Array: \n";
    print(A, size);
    sort01(A, size);
    cout<<"\nSorted Array: \n";
    print(A, size);
    cout<<endl;
    return 0;
}

