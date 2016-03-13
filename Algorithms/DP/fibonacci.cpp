#include <iostream>
#include <cstring>
using namespace std;

int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}


// Memoization using lookup table fib[] (TopDown Approach)
int fibonacciTDN(int n, int fib[]) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (fib[n] != 0) return fib[n];
	// memoization
	fib[n] = fibonacciTDN(n-1, fib) + fibonacciTDN(n-2, fib);
	return fib[n];
}

// Tabulation method (BottomUp Approach)
int fibonacciBUP(int n) {
	int f[n+1];
	f[0] = 0; f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = f[i-1] + f[i-2];
	return f[n];
}

int main() {
	int *fib = new int[100];
	memset(fib, 0, sizeof(fib));
	/*for (int i = 0; i < 40; i++) {
		cout<<fibonacci(i)<<" ";
	}*/
	/*for (int i = 0; i < 40; i++) {
		cout<<fibonacciTDN(i, fib)<<" ";
	}*/
	for (int i = 0; i < 40; i++) {
		cout<<fibonacciBUP(i)<<" ";
	}

	delete [] fib;
	return 0;
}