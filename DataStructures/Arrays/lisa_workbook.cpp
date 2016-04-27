// https://www.hackerrank.com/challenges/bear-and-workbook
#include <iostream>
#include <cstdio>
using namespace std;

int findSpecialProblems(int *T, int N, int K) {
	int spl = 0, prob = 0, index = 1, Ki = 0, i, j;
	for (i = 1; i <= N; i++) {
		prob = T[i-1];
		//cout<<"Page# "<<i<<" #Probs: "<<prob<<endl;
		// problems in a page
		for (j = 1; j <= prob; j++) {
			//cout<<index<<"->"<<j<<" ";
			if (index == j) spl++;
			Ki++;			
			if (Ki == K && j != prob) {
			 	index++;
			 	Ki = 0;
			}
		}
		Ki = 0;
		if (j-1 == prob) index++;
		//cout<<endl;
	}
	return spl;
}

int main() {
	int N, K;
	freopen("lisa_workbook.txt", "r", stdin);

	cin>>N>>K;
	int *T = new int[N];
	for (int i = 0; i < N; i++)
		cin>>T[i];

	cout<<findSpecialProblems(T, N, K)<<endl;

	delete [] T;

	return 0;
}