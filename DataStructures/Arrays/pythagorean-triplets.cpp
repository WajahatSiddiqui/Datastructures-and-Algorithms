#include <iostream>
using namespace std;
//#define SQRT(X) (X)*(X)

int SQRT(int i) {
    return i*i;
}

void findTriplets(int A[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            for (int k = j+1; k < size; k++) {
                if (SQRT(i) + SQRT(j) == SQRT(k)) {
                    cout<<"Triplets: "<<i<<" "<<j<<" "<<k<<endl;
                    return;
                }
            }
        }
    }
}

int main() {
    int A[] = {11, 12, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);

    findTriplets(A, size);

    return 0;
}
