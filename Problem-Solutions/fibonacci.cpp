#include <iostream>
#include <cstring>
using namespace std;

int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciDP(int n, int fib[]) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (fib[n] != 0) return fib[n];
	// memoization
	fib[n] = fibonacciDP(n-1, fib) + fibonacciDP(n-2, fib);
	return fib[n];
}

int main() {
	int *fib = new int[100];
	memset(fib, 0, sizeof(fib));
	/*for (int i = 0; i < 40; i++) {
		cout<<fibonacci(i)<<" ";
	}*/
	for (int i = 0; i < 40; i++) {
		cout<<fibonacciDP(i, fib)<<" ";
	}
	delete [] fib;
	return 0;
}