/**
 * Find two pairs whose sum is equal
 * i.e., four numbers whose sum is equal in an array
 * I/P: A[] = {3, 4, 7, 1, 2, 9}
 * O/P: (3, 7) (1, 9)
 *      (4, 7) (2, 9)
 */

#include <iostream>
#include <map>
#include <utility>
using namespace std;

/**
 * Brute force approach
 * Time complexity: O(n^4)
 * Space complexity: O(1)
 */
void findPairUsingArrays(int A[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            for (int k = j+1; k < size; k++) {
                for (int l = k+1; l < size; l++) {
                    if (A[i] + A[j] == A[k] + A[l]) {
                        cout<<"("<<A[i]<<", "<<A[j]<<"), "
                            <<"("<<A[k]<<", "<<A[l]<<")"<<endl;
                    }
                }
            }
        }
    }
}
/**
 * Uses HashMap to store key = sum value = pair(i,j)
 * using the sum as the key retrieve a pair
 * Time complexity:  O(n^2)
 * Space complexity: O(n)
 */
void findPair(int A[], int size) {

    map<int, pair<int, int> > hash;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            sum = A[i] + A[j];
            // sum is not found in the hashmap
            if (hash.find(sum) == hash.end()) {
                pair<int, int> p = make_pair(A[i], A[j]);
                // add to the hashmap
                hash[sum] = p;
            } else { // sum is found in the hash map
                pair<int, int> pp = hash[sum];
                cout<<"("<<pp.first<<", "<<pp.second<<"), "
                    <<"("<<A[i]<<", "<<A[j]<<")"<<endl;
            }
        }
    }
}

int main() {
 int A[] = {3, 4, 7, 1, 2, 9};
 int size = sizeof(A)/sizeof(A[0]);

 cout<<"Pair using traversing arrays\n";
 findPairUsingArrays(A, size);
 cout<<"Pair using hash map\n";
 findPair(A, size);

 return 0;
}

