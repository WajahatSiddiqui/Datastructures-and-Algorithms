// https://www.hackerrank.com/challenges/utopian-tree
#include <iostream>
using namespace std;
int LUT[60] = {0};

void print(int n) {
	for (int i = 0; i < n; i++)
		cout<<LUT[i]<<" ";
	cout<<endl;
}
int height(int n) {
	if (!LUT[n]) {
		if (n%2 == 0)
			LUT[n] = height(n-1) + 1;
		else
			LUT[n] = height(n-1) * 2;
	}
	return LUT[n];
}

int main() {
	LUT[0] = 1;
	LUT[1] = 2;
	int n = 60;
	cout<<height(n)<<endl;
	print(n);
};