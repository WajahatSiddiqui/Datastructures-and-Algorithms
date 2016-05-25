#include <iostream>
using namespace std;

/*float sqrt(double n) {
	float lo = 0.0f;
	float hi = n+1;

	float mi;
	// approx with an epsilon
	while (hi-lo > 0.00001) {
		mi = (lo + hi) /2;

		if (mi*mi < n)
			lo = mi;
		else
			hi = mi;
	}
	return lo;
}*/

float absolute(float n) {
	n = n < 0 ? -n : n;
	return n;
}

// Newton Raphsons Method
float sqrt(int x)
{
    const float difference = 0.00001;
    float guess = 1.0;
    while(absolute(guess * guess - x) >= difference){
        guess = (x/guess + guess)/2.0;
    }
    return guess;
}

int main() {
	cout<<"sqrt(9) = " << sqrt(9) << endl
	    <<"sqrt(5) = "<< sqrt(5) << endl;

	return 0;
}