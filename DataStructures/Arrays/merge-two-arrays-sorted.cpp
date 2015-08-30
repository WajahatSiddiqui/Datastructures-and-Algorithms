#include <iostream>
using namespace std;

void merge(int A1[], int size1, int A2[], int size2) {
    int i1, j1, k;
    i1 = j1 = k = 0;
    int i2 = size1-1;
    int j2 = size2-1;

    int *B = new int[size1+size2];

    while (i1 <= i2 && j1 <= j2) {
        if (A1[i1] <= A2[j1]) {
            B[k++] = A1[i1++];
        } else if (A2[j1] < A1[i1]) {
            B[k++] = A2[j1++];
        }
    }

    if (i1 >= i2) {
        for (int i = j1; i <= j2; i++)
            B[k++] = A2[i];
    }
    if (j1 >= j2) {
        for (int i = i1; i <= i2; i++)
            B[k++] = A1[i];
    }

    for (int i = 0; i < k; i++)
        cout<<B[i]<<" ";
    cout<<endl;
    delete [] B;
}

int main() {
    int A1[] = {0, 1, 3, 9, 20, 21, 22, 33, 44, 55};
    int A2[] = {1, 2, 4, 5, 6, 7, 8, 9, 55, 100, 101, 102, 102};
    int size1 = sizeof(A1)/sizeof(A1[0]);
    int size2 = sizeof(A2)/sizeof(A2[0]);

    merge(A1, size1, A2, size2);

    return 0;
}
