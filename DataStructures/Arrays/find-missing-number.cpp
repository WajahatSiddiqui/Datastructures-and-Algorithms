/**
 * Find Missing Number in a 1d array
 * where all numbers are positive 
 * and array is from 1 to n
 */
#include <iostream>
using namespace std;

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void sort(int A[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (A[i] > A[j]) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

/**
 * Brute force approach
 * 1) Sort the given array
 * 2) Compare elements of array with the upcoming number
 * 3) if it is not equal, upcoming number is the missing number.
 * Worst Case: T(n) = O(n^2)
 */
void findMissingBruteForce(int A[], int size) {
    sort(A, size);
    for (int i = 1, j = 0; i < size && j < size; i++,j++) {
        if (A[j] != i) {
            cout<<"Missing number = "<<i<<endl;
            return;
        }
    }
}
/**
 * 1) Find the sum of the array say sum.
 * 2) Use the formula for sum of n numbers say N
 * 3) Missing Number = N - sum
 * T(n) = O(n)
 */
void findMissing(int A[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += A[i];
    size++; // Array indices start from 0 so increment size
    //using sigma(i = 0, n)i = n*(n+1)/2
    cout<<"Missing number = "<<((size*(size+1))/2 - sum)<<endl;
}

void findMissingXOR(int A[], int size) {
    int X = A[0] , Y = 1, missingNumber = 0;
    for (int i = 1; i < size; i++)
        X ^= A[i];
    for (int j = 2; j <= size+1; j++)
        Y ^= j;
    missingNumber = X^Y;
    cout<<"Missing number = "<<missingNumber<<endl;
}



int main() {
    int A[] = {1, 2, 4, 6, 3, 8, 7};
    int size = sizeof(A)/sizeof(A[0]);

    findMissing(A, size);
    findMissingBruteForce(A, size);
    findMissingXOR(A, size);
    return 0;
}
