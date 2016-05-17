// factorial of a very large number
#include <iostream>
using namespace std;
#define SIZE 500 // MAX SIZE OF ARRAY

int multiply(int res[], int x, int res_size) {
	int carry = 0, product = 0;
	for (int i = 0; i < res_size; i++) {
		product = res[i]*x + carry;
		res[i] = product%10;
		carry = product/10;
	}

	while(carry) {
		res[res_size] = carry%10;
		carry /= 10;
		res_size++;
	}
	return res_size;
} 

void factorial(int N) {
	int res[SIZE] = {0};
	int res_size = 1;
	res[0] = 1;
	for (int i = 2; i <= N; i++)
		res_size = multiply(res, i, res_size);

	for (int i = res_size-1; i >= 0; i--)
		cout<<res[i];
}

int main() {
	factorial(25);
	return 0;
} 