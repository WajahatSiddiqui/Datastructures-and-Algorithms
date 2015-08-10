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

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

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


/**
 * http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
 * T(n) = O(n)
 * S(n) = O(1)
 */
void boyermoore_voting_algorithm(int A[], int size) {
    // find candidate
    int cand = 0, count = 1, maj_index = 0;
    for (int i = 1; i < size; i++) {
        // sweep and change the current candidate and counter
        // initally if counter = 0 current candidate is e and counter = 1
        if (A[maj_index] == A[i]) count++;
        else count--; 
        // if counter is non zero, if e is current candidate increment
        // else decrement
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    cand = A[maj_index];
    // check if the candidate is majority
    count = 0;
    for (int i = 0; i < size; i++) {
        if (A[i] == cand)
            count++;
    }
    if (count >= size/2) {
        cout<<"Majority element: "<<cand<<endl;
    } else {
        cout<<"Majority element: None"<<endl;
    }

}

int main() {
    int A[] = {3, 2, 2, 4, 2, 2, 3, 2, 2, 3, 3, 3, 3, 3};
    int size = sizeof(A)/sizeof(A[0]);

    printArray(A, size);
    //findMajorityElement(A, size);
    boyermoore_voting_algorithm(A, size);

    int B[] = {3, 3, 2, 2, 4, 4};
    size = sizeof(B)/sizeof(B[0]);
    printArray(B, size);
    //findMajorityElement(B, size);
    boyermoore_voting_algorithm(B, size);

    return 0;
}
