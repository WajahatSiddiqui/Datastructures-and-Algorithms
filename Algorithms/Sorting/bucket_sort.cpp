#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Best case: O(n+k)
// Avg. case: O(n+k)
// Worst case: O(n^2)
// Space: O(n.k)
void bucket_sort(float A[], int size);

int main() {
	float A[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
	int size = sizeof(A)/sizeof(int);
	cout<<"Size = "<<size<<endl;
	cout<<"Input Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	bucket_sort(A, size);
	cout<<"\nBucket Sorted Array: \n";
	for (int i = 0; i < size; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}

void bucket_sort(float A[], int size) {
    vector<float> v[size];
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
}

