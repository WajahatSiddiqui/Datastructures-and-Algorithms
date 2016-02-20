#include <iostream>
using namespace std;

void swap(char *a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void permute(char A[], int l, int r) {
	int i;
	if (l == r) cout<<A<<endl;
	else {
		for (i = l; i <= r; i++) {
			swap(&A[l], &A[i]);
			permute(A, l+1, r);
			swap(&A[l], &A[i]); // backtrack
		}
	}
}

int main() {
	char A[] = "abcd";
	permute(A, 0, 3);
	return 0;
}