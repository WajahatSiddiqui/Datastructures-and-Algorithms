/**
 * To find the maximum contiguous sum in a sub array
 * of a 1d array
 */
#include <iostream>
using namespace std;
#define max(x,y) y > x ? y : x

/**
 * 1) Initialize 
 *  max_so_far = max_ending_here = 0
 * 2) loop for each element in the array
 *  a) max_ending_here = max_ending_here + A[i]
 *  b) if max_ending_here < 0 => max_ending_here = 0
 *  c) else if (max_ending_here < max_so_far)
 *      max_so_far = max_ending_here;
 *  return max_so_far
 *  T(n) = O(n)
 *  S(1) = O(1)
 *  Source: https://en.wikipedia.org/wiki/Maximum_subarray_problem
 */
void maxSubArrayKadane(int A[], int size) {
    int max_so_far = 0, max_ending_here = 0;
    for (int i = 0; i < size; i++) {
        max_ending_here += A[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        else if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    cout<<"Max contiguous subarray sum = "<<max_so_far<<endl;
}


/**
 * 1) Initialize curr_max and max_so_far
 * 2) Start from index 1, update curr_max with
 * maximum of (A[i], A[i]+curr_max)
 * 3) update max_so_far with maximum of curr_max and
 * max_so_far
 * 4) return max_so_far
 * T(n) = O(n)
 * S(n) = O(1)
 */
void maxSubArray(int A[], int size) {
    int curr_max = A[0], max_so_far = A[0];
    for (int i = 1; i < size; i++) {
        curr_max = max(A[i], A[i]+curr_max);
        max_so_far = max(curr_max, max_so_far);
    }
    cout<<"Max contiguous subarray sum = "<<max_so_far<<endl;
}

int main() {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //int A[] = {-2, -1, -4, -5, 3, -9, 1};
    int size = sizeof(A)/sizeof(A[0]);

    maxSubArray(A, size);
    maxSubArrayKadane(A, size);

    return 0;
}
