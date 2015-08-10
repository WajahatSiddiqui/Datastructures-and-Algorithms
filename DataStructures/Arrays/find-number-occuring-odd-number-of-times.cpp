/**
 * Find the number which is repeated
 * odd number of times in a given array
 * which has even number of elements already
 * and atleast on number is repeated odd
 * number of times
 */
#include <iostream>
using namespace std;

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}


/**
 * XOR all the numbers and result 
 * should be the number of odd times
 * repeated
 */
void findOddNumber(int A[], int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res = res ^ A[i];
    }
    cout<<"Element repeated odd number of times : "<<res<<endl;
}


int main() {

    int A[] = {1, 1, 2, 2, 3, 3, 3};
    int size = sizeof(A)/sizeof(A[0]);

    printArray(A, size);
    findOddNumber(A, size);

    return 0;
}
