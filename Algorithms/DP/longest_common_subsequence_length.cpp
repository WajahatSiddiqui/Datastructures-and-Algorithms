/**
 * Longest Common Subsequence:
 * Given two strings, find longest common subsequence between them.
 * https://www.youtube.com/watch?v=NnD96abizww&index=2&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
 */
 #include <iostream>
 using namespace std;


void print(unsigned int **T, int M, int N) {
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			cout<<T[i][j]<<" ";
		}
		cout<<endl;
	}		
	cout<<endl;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int findCommonSubsequence(char str1[], char str2[], int M, int N) {
	unsigned int solution = 0;
	unsigned int **T = new unsigned int*[M+1];
	for (int i = 0; i <= M; i++)
		T[i] = new unsigned int[N+1];
	//print(T, M, N);
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (str1[j-1] == str2[i-1]) {
				T[i][j] = T[i-1][j-1] + 1;
			}
			else
				T[i][j] = max(T[i-1][j], T[i][j-1]);
		}
	}
	print(T, M, N);
	solution = T[M][N];
	for (int i = 0; i <= M; i++)
		delete [] T[i];
	delete [] T;
	return solution;
}

 int main() {
 	char str1[] = {'a', 'b', 'e', 'l', 'k', 'q', 'd'};
 	int N = sizeof (str1)/sizeof(str1[0]);
 	char str2[] = {'b','l','a','q','m', 'd', 'b'};
 	int M = sizeof (str2)/sizeof(str2[0]);

 	cout<<findCommonSubsequence(str1, str2, M, N)<<endl;
 	return 0;
 }