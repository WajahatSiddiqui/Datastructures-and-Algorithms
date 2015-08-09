#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 * T(n) = O(n^2)
 */
void findTwoElements(int A[], int size, int x) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (A[i] + A[j] == x) {
                if (A[j] < 0)
                    cout<<"Two Elements Are: "<<A[i]<<A[j]<<"="<<x<<endl;
                else
                    cout<<"Two Elements Are: "<<A[i]<<"+"<<A[j]<<"="<<x<<endl;
                found = true;
                break;
            }
        }
    }
    if (!found)
        cout<<"Elements not found!"<<endl;
}

/**
 * 1) Initialize two indexes which are candidates in the array
 *  l = 0, r = size-1; // since size = array size
 * 2) loop while l < r
 *  sum = A[l] + A[r]
 *  (i) if sum == x print A[l], A[r]
 *  (ii) if sum < x r--
 *  (iii) if sum > x l++
 *
 * T(n) = O(n)
 */
void findTwoElementsEfficiently(int A[], int size, int x) {
    int l = 0, r = size-1, sum = 0;
    bool found = false;
    while (l < r) { 
        sum = A[l] + A[r];
        if (sum == x) {
           if (A[r] < 0)
                cout<<"Two Elements Are: "<<A[l]<<A[r]<<"="<<x<<endl;
           else
                cout<<"Two Elements Are: "<<A[l]<<"+"<<A[r]<<"="<<x<<endl;
            found = true;
            break;
        } else if (sum < x) r--;
        else l++;
    }
    if (!found)
        cout<<"Elements not found!"<<endl;
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 0;
    int A[] = {17, 5, 4, 2, 1, -2};
    int size = sizeof(A)/sizeof(A[0]);

    printArray(A, size);
    findTwoElements(A, size, atoi(argv[1]));
    findTwoElementsEfficiently(A, size, atoi(argv[1]));
    return 0;
}
