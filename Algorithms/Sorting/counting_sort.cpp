/**
 * Counting Sort
 * A non comparison based sorting
 * Algorithm:
 * 1) Count the number of objects in the input array
 *    and store it in the count array
 * 2) Modify the count array so that each element of
 *    each index stores the sum of its previous count
 * 3) Build the output array from the input sequence
 *    using the count array and decrease the count by 1
 * T(n) = O(n+k) n, no. of elements, k: range of output
 */

 #include <iostream>
 #include <string.h>
 using namespace std;
 #define RANGE 10

 void printArray(int A[], int size) {
 	for (int i = 0; i < size; i++) cout<<A[i]<<" ";
 	cout<<endl;
 }

 void counting_sort(int A[], int size) {
 	int count[RANGE+1], i;
 	int output[size];
 	memset(count, 0, sizeof(count));

 	// Count the number of objects in the input array
 	// and store it in the count array
 	for (i = 0; i < size; ++i) {
 		++count[A[i]];
 	}
 	//printArray(count, RANGE+1);

 	// Modify the count array such that each element
 	// of each index stores the sum of previous counts
 	for (i = 1; i <= RANGE; i++) {
 		count[i] += count[i-1];
 	}
    //printArray(count, RANGE+1);
 	// Build each object from the input sequence
 	// followed by decreasing countS
 	for (i = 0; i < size; i++) {
 		output[count[A[i]]-1] = A[i]; // to compensate the index 0
 		--count[A[i]];
 	}
 	//printArray(output, size);

 	// Store back the output into the input array
 	for (int i = 0; i < size; i++) A[i] = output[i];
 }

 int main() {
	int A[] = {2, 2, 1, 1, 1, 3, 8, 5, 6};
	int size = sizeof(A)/sizeof(int);
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: \n";
	printArray(A, size);
	cout<<"\nCounting Sorted Array: \n";
	counting_sort(A, size);	
	printArray(A, size);
	return 0;
}