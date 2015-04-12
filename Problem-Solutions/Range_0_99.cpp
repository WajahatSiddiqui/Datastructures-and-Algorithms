// Problem statement: http://www.geeksforgeeks.org/print-missing-elements-that-lie-in-range-0-99/
// Algorithm:
#include <iostream>
using namespace std;
#define LIMIT 100

bool B[LIMIT] = {false, };

static void printResult(int A[], int size) {
    int i = 0, j = 0;
    for (int i = 0; i < size; i++) {
        if (A[i] >= 0 && A[i] <= 99)
            B[A[i]] = true;
    }
    i = 0;
    while (i < LIMIT) {
        // i is missing, print the range
        if (B[i] == false) {
            for (j = i+1; j < 100 && B[j] == false; j++);
            if (i+1 == j)
                cout<<i<<endl;
            else
                cout<<i<<"-"<<j-1<<endl;

            i = j;
        } else
            i++;
    }
}

int main() {
    int A[] = {105, 2, 4, 88, -1};
    int size = sizeof(A)/sizeof(A[0]);
    cout<<"Size = "<<size<<endl;
    cout<<"Input Array: "<<endl;
    for (int i = 0; i < size; i++)
        cout<<A[i]<<" " ;
    cout<<"\n===============================\n";
    printResult(A, size);

    return 0;
}
