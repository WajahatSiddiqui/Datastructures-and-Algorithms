/**
 * Binary Search
 * Best case: O(1)
 * Avg case: O(logn)
 * Worst case: O(logn)
 * Search for key in Array A, if found returns the index position
 * else return KEY_NOT_FOUND
 * Precondtion: A has to be sorted
 * @Author: Wajahat Siddiqui
 */
#include <iostream>
using namespace std;
#define KEY_NOT_FOUND -1

// Algorithm (Recursive): 
// 1) if Array A is empty iMax < iMin then return KEY_NOT_FOUND
// 2) calculate the middle position to cut set into two halves
// 3) if key is found then return iMid
// 4) else if key < A[iMid] recursivey search in iMin, iMid-1
// 5) else if key > A[iMid] recursively search in iMid+1, iMax
int binary_search_recursive(int A[], int iMin, int iMax, int key) {
   if (iMax < iMin) return KEY_NOT_FOUND;
   else {
       int iMid = (iMin + (iMax-iMin)/2);
       //cout<<"iMin = "<<iMin<<" iMax = "<<iMax<<" iMid = "<<iMid<<endl;
       // Key found in iMid itself !
       if (key == A[iMid])
           return iMid;
       // search the key in the lower subset
       else if (key < A[iMid])
           binary_search_recursive(A, iMin, iMid-1, key);
       // search the key in the upper subset
       else if (key > A[iMid])
           binary_search_recursive(A, iMid+1, iMax, key);
   }
}

// Algorithm (Iterative):
// 1) iterate when iMin <= iMax
// 2) cut set into two halves
// 3) if key is found in iMid itself then return iMid
// 4) else if key < A[iMid] update iMax = iMid - 1
// 5) else if key > A[iMid] update iMin = iMid + 1
// 6) continue step 1 until key is found else return KEY_NOT_FOUND
int binary_search_iterative(int A[], int iMin, int iMax, int key) {
    // loop from iMin to iMax
    while (iMin <= iMax) {
        int iMid = (iMin + (iMax-iMin)/2);
        //cout<<"iMin = "<<iMin<<" iMax = "<<iMax<<" iMid = "<<iMid<<endl;
        // Key found in iMid itself!
        if (key == A[iMid])
            return iMid;
        // set the max index to lower subpart
        else if (key < A[iMid])
            iMax = iMid-1;
        else
        // set the min index to upper subpart
            iMin = iMid+1;
    }
    // result not found
    return KEY_NOT_FOUND;
}

/**
 * Variation of binary search: Lower Bound
 * Find an element X in A[] such that K <= X where K is the key
 */
 int lowerBound(int A[], int size, int key) {
    int lo = 0, hi = size - 1, mid;
    while (lo <= hi) {
      mid = (lo + (hi - lo)/2);
      if (key <= A[mid] && (mid == 1 || key > A[mid - 1])) return mid;
      else if (key <= A[mid]) hi = mid - 1;
      else lo = mid + 1;
    }
    return mid;
 }

 /**
 * Variation of binary search: Upper Bound
 * Find an element X in A[] such that K < X where K is the key
 */
 int upperBound(int A[], int size, int key) {
    int lo = 0, hi = size - 1, mid;
    while (lo <= hi) {
      mid = (lo + (hi - lo)/2);
      if (key < A[mid] && (mid == 1 || key <= A[mid - 1])) return mid;
      else if (key < A[mid]) hi = mid - 1;
      else lo = mid + 1;
    }
    return mid;
 }

int main() {
	int A[] = {1, 2, 3, 4, 4, 6, 8};
	int size = sizeof(A)/sizeof(int);
  int key = 4, indexPosition = KEY_NOT_FOUND;
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: ";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
  cout<<endl;
	if ((indexPosition = binary_search_iterative(A, 0, size-1, key)) != KEY_NOT_FOUND) {
        cout<<key<<" Found !"
            <<"\nIndex position: "<<indexPosition;
  } else
        cout<<key<<" Not found :(\n";
  cout<<endl;
  int l = lowerBound(A, size, 5);
  int u = upperBound(A, size, 5);
  cout<<"Lower Bound of 5 in A is: "<<l<<" whose value is "<<A[l]<<endl;
  cout<<"Upper Bound of 5 in A is: "<<u<<" whose value is "<<A[u]<<endl;

	return 0;
}


