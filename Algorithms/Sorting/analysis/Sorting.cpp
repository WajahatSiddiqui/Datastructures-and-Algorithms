#include "Sorting.h"
/*#include <algorithm>
#include <vector>*/

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Sorting::selection_sort(int A[], int size) {
    // minimum index for selection sort
    int min_index = 0;
    // Advance the position to the entire array
    // A[0] ... A[size -1]
    for (int i = 0; i < size; i++) {
        // Find the minimum element in the unsorted array
        // Assume mimimum index is first element (i)
        min_index = i;
        // test this minimum index against all the other
        // elements in the array
        for (int j = i+1; j < size; j++) {
            // compare left most element with current minimum
            if (A[j] < A[min_index])
                // update the minimum index
                min_index = j;

        }
        // minimum index is found, test wheather
        // this is different from current left most
        if (A[i] != A[min_index])
            // exchange with unsorted
            swap(&A[i], &A[min_index]);
    }
}

void Sorting::bubble_sort(int A[], int size) {
    // compare each of the two elements (pairs)
    // exchange if there are out of order
    for (int i = 0; i < (size - 1); i++) {
        for (int j = 0; j < (size - i - 1); j++) {
            if (A[j] > A[j+1])
                swap(&A[j], &A[j+1]);
        }
    }
}

// Algorithm:
// 1) i = next element, j = prev element
// 2) set key = A[i]
// 3) find the position in the list to insert the key correctly
// 4) shift all the elements to next place
// 5) insert the key in the element found
// Best case: O(n)
// Avg. case: O(n^2)
// Worst case: O(n^2)
// Sorts array A in increasing order
// Qualities: 
// 1) Efficient - for small data sets and other quadratic algorithms
// 2) Stable - Doesn't change the relative order
// 3) Inplace - Doesn't need additional memory sorts as it receives online

void Sorting::insertion_sort(int A[], int size) {
	int i, j, key;
    for (i = 1; i < size; i++) {
        key = A[i];
        for (j = i - 1; j >= 0 && A[j] > key; j--) {
            A[j+1] = A[j];
        }
        A[j+1] = key;
    }
}


void merge(int A[], int low, int mid, int high) {
    // Initialize
    int B[100], i, j, k, l, start;
    start = low;
    i = low;
    k = mid+1;
    j = high;
    l = i;

    // Form B Array
    while (i <= mid && k <= j) {
        if (A[i] <= A[k])
            B[l++] = A[i++];
        else
            B[l++] = A[k++];
    }

    // Boundary is crossed
    // copy the left over
    if (i > mid) {
        while (k <= j)
            B[l++] = A[k++];
    } else if (k > j) {
        while (i <= mid)
            B[l++] = A[i++];
    }

    // Copy B into A
    for (l = start; l <= j; l++) {
        A[l] = B[l];
    }
}


// low represents starting index
// high represents size-1, ending index
void merge_sort_util(int A[], int low, int high) {
	if (low >= high) return;
    int mid = (low + high)/2; // Divide
    merge_sort_util(A, low, mid); //Conquer
    merge_sort_util(A, mid+1, high);
    merge(A, low, mid, high); //Combine
}

void Sorting::merge_sort(int A[], int size) {
    merge_sort_util(A, 0, size-1);
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int  i = low - 1;
    for (int j = low; j <= high-1; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    return i+1;
}

// low represents starting index
// high represents size-1, ending index
// Best case: O(nlogn)
// Avg. case: O(nlogn)
// Worst case: O(n^2)

void quick_sort_util(int A[], int low, int high) {
    if (low < high) {
        // Partition the array based on some pivot
        int pivot = partition(A, low, high);
        // Decompose and sort recursively
        quick_sort_util(A, low, pivot-1);
        quick_sort_util(A, pivot+1, high);
    }
}

void Sorting::quick_sort(int A[], int size) {
	quick_sort_util(A, 0, size-1);
}



// Best case: O(nlogn)
// Avg. case: O(n^2)
// Worst case: O(n^2)
void Sorting::shell_sort(int A[], int size) {
	  int i,j;
    // start with the bigger gap and reduce it gradually
    for (int gap = size/2; gap > 0; gap /= 2) {
        // Perform insertion sort within the gap
        for (i = gap; i < size; i++) {
            int key = A[i];
            // shift earlier gap sorted array until the correct location of A[i] is found
            for (j = i; j >= gap && A[j-gap] > key; j-=gap) A[j] = A[j-gap];
            // put the key into correct location
            A[j] = key;
        }
    }

}



// Best case: O(n+k)
// Avg. case: O(n+k)
// Worst case: O(n^2)
// Space: O(n.k)
void Sorting::bucket_sort(int A[], int size) {
/*    vector<int> v[size];
    int vi; // index into bucket
    // Create the buckets
    for (int i = 0; i < size; i++) {
        vi = A[i]*size;
        v[vi].push_back(A[i]);
    }
    // sort each of the individual lists in the bucket
    for (int i = 0; i < size; i++)
        sort(v[i].begin(), v[i].end());

    // combine all the result into the array
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < v[i].size(); j++)
            A[index++] = v[i][j];
    }
*/}

void Sorting::counting_sort(int A[], int size) {

}

void Sorting::radix_sort(int A[], int size) {

}

void Sorting::heap_sort(int A[], int size) {

}
