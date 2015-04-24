// http://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/
#include <iostream>
#include <stdlib.h>
using namespace std;

// iterative
// complexity: O(n)
static int square(int n) {
    // handle zero
    if (n == 0) return 0;
    
    // handle -ve
    if (n < 0) n = -n;

    int result = n;
    for (int i = 1; i < n; i++) {
        result += n;
    }
    return result;
}

// recursive
// complexity: O(logn)
// if n is even, n = 2x => n^2 = (2^2)(x^2) = 4x^2 
// if n is odd, n = (2x+1) => n^2 = (2x+1)^2 = 4x^2 + 4x + 1
// where x = floor(n/2) which can be calculated as n >> 1
static int square_r(int n) {
    // handle zero
    if (n == 0) return 0;

    // handle -ve
    if (n < 0) n = -n;

    // evaluate floor(n/2)
    int x = n >> 1;

    // cout<<"x = "<<x<<endl;
    // n is even
    if (n % 2 == 0)
        return (square_r(x)<<2);
    else // n is odd
        return ((square_r(x)<<2) + (x<<2) + 1);
}

int main (int argc, char *argv[]) {
    if (argc < 2) {
        cout<<"Invalid argument, exiting...\n";
        return 0;
    }
    int n = atoi(argv[1]);
    cout<<n<<"^2"<<" = "<<square_r(n)<<endl;
    return 0;
}
