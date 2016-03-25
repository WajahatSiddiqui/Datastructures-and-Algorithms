#include <iostream>
using namespace std;
#define NOT_FOUND -1


/**
 * Naive Pattern Matching 
 * T(n) = O(NM)
 * Algorithm:
 * (i)  when a character is matched increment the indices (i, j),
 * k tracks the start position of a string
 * (ii) else reset the jth index and bring the index of i to prev
 * (iii) if pattern matches return the start position
 * else return not found.
 */ 

int findMatch(char T[], char P[], int N, int M) {
	int i = 0, j = 0, k = 0;
	while (i < N && j < M) {
		if (T[i] == P[j]) {
			i++;
			j++;
		} else {
			j = 0;
			k++;
			i = k;
		}
		if (j == M-1) return k;
	}
	return NOT_FOUND;
}

void print(int A[], int N) {
	for (int i = 0; i < N; i++) cout<<A[i]<<" ";
	cout<<endl;
}

int* createArray(char P[], int M) {
	int *lps = new int[M];
	int j = 0, i = 1;
	while (i < M) {
		if (P[i] == P[j]) {
			lps[i] = j + 1;
			i++;
			j++;
		} else {
			if (j != 0)
				j = lps[j-1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

int KMP(char T[], char P[], int N, int M) {
	int *lps = createArray(P, M);
	print(lps, M-1);
	int i = 0, j = 0, k = 0;
	while (i < N && j < M) {
		if (T[i] == P[j]) {
			i++;
			j++;
		} else {			
			if (j != 0) {
				j = lps[j-1];
				k = i - j;
			}
			else
				i++;
		}
		if (j == M-1)
			return k;
	}
	delete [] lps;
	return NOT_FOUND;
}

int main() {
	char T[] = "abcxabcdabcdabcy"; // text
	int N = sizeof(T)/sizeof(T[0]);
	char P[] = "abcdabcy"; // pattern
	int M = sizeof(P)/sizeof(P[0]);
	cout<<"Text   : "<<T<<endl
		<<"Pattern: "<<P<<endl
		<<"Match  : "<<findMatch(T, P, N, M)<<endl
		<<"KMP    : "<<KMP(T, P, N, M)<<endl;
	return 0;
}