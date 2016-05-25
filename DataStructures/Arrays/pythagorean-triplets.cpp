#include <iostream>
#include <algorithm>
using namespace std;
//#define SQRT(X) (X)*(X)

int SQRT(int i) {
    return i*i;
}

/**
 * Find the squares and check if square of hypotenuse
 * is equal square of two sides
 * T(N) = O(N^3)
 **/
void findTriplets(int A[], int size) {
    int a, b, c;
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            for (int k = j+1; k < size; k++) {
                a = SQRT(A[i]); b = SQRT(A[j]); c = SQRT(A[k]);
                //cout<<a<<" "<<b<<" "<<c<<endl;
                if (a == b + c || b == a + c || c == a + b) {
                    cout<<"Triplets: "<<A[i]<<" "<<A[j]<<" "<<A[k]<<endl;
                    break;
                }
            }
        }
    }
}

/**
 * T(N) = O(N^2logN)
 **/
void findTripletsEfficient(int A[], int size) {
    for (int i = 0; i < size; i++)
        A[i] = A[i]*A[i];
    sort(A, A+size);

    for (int i = size-1; i >= 0; i--) {
        int l = 0;
        int r = size-1;
        while (l < r) {
            if (A[l] + A[r] == A[i]) {
                cout<<"Triplets (E): "<<A[l]<<" "<<A[r]<<" "<<A[i]<<endl;
                break;
            } else {
                if (A[l] + A[r] < A[i]) l++;
                else r--;
            }
        }
    }
}

int main() {
    int A[] = {11, 12, 4, 3, 5, 12, 13, 160, 231, 281};
    int size = sizeof(A)/sizeof(A[0]);

    findTriplets(A, size);
    findTripletsEfficient(A, size);

    return 0;
}
