// Program to multiply on huge number
#include <iostream>
using namespace std;

void multiply(int res[], int x, int N) {
	int carry = 0, prod = 0;
	for (int i = 0; i < N; i++) {
		prod = res[i] * x + carry;
		res[i] = prod%10;
		carry = prod/10;
	}
	while (carry != 0) {
		res[N] = carry %10;
		carry /= 10;
		N++;
	}

	for (int i = N-1; i >= 0; i--)
		cout<<res[i];
}

int main() {
	int res[100] = {2, 1, 1};
	multiply(res, 24, 3);
	return 0;
}