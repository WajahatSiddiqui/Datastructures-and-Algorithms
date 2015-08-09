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
    return 0;
}
