/**
 * Radix Sort
 * A non comparison based sorting
 * Algorithm:
 * 1) Divide the numbers based on the digits 
 *    by getting the maximum number and find the max digits
 * 2) for each max digit place 1, 10, 100, ... count sort
      the digits
 * T(n) = O(d* (n+k)) n, no. of elements, k: range of output
 * d is the number of digits
 * if d is very large value K and k <= n^c  O((n+b)*logk)
 * if b = n then O(nlogn)
 */

 #include <iostream>
 #include <string.h>
 #include <limits.h>
 using namespace std;
 #define RANGE 10

 void printArray(int A[], int size) {
 	for (int i = 0; i < size; i++) cout<<A[i]<<" ";
 	cout<<endl;
 }

 void counting_sort(int A[], int size, int exp) {
 	int count[10] = {0};
 	int output[size], i;
 	
 	// Count the number of objects in the input array
 	// and store it in the count array
 	for (i = 0; i < size; ++i) {
 		++count[(A[i]/exp) % 10];
 	}
 	//printArray(count, RANGE+1);

 	// Modify the count array such that each element
 	// of each index stores the sum of previous counts
 	for (i = 1; i < 10; i++) {
 		count[i] += count[i-1];
 	}
    //printArray(count, RANGE+1);
 	// Build each object from the input sequence
 	// followed by decreasing countS
 	for (i = size - 1; i >= 0; i--) {
        output[count[ (A[i]/exp)%10 ] - 1] = A[i];
        count[ (A[i]/exp)%10 ]--;
    }
 	//printArray(output, size);

 	// Store back the output into the input array
 	for (i = 0; i < size; i++) A[i] = output[i];
 }

 int getMax(int A[], int size) {
 	int max = INT_MIN;
 	for (int i = 0; i < size; i++)
 		if (A[i] > max) max = A[i];
 	return max;
 }

 void radix_sort(int A[], int size) {
 	int max = getMax(A, size);

 	for (int exp = 1; max/exp > 0; exp *= 10)
 		counting_sort(A, size, exp);
 }

 int main() {
	int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int size = sizeof(A)/sizeof(int);
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: \n";
	printArray(A, size);
	cout<<"\nRadix Sorted Array: \n";
	radix_sort(A, size);	
	printArray(A, size);
	return 0;
}