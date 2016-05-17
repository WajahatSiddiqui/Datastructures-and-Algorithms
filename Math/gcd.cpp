#include <iostream>
using namespace std;

/**
 * gcd(A, 0) = A
 * gcd(A, B) = gcd(B, A%B)
 */
int gcd(int A, int B) {
	if (B == 0)
		return A;
	return gcd(B, A%B);

}

int main() {
	int A = 7, B = 5;
	cout << gcd(A, B) << endl;
	return 0;
}