// http://www.geeksforgeeks.org/how-to-turn-off-a-particular-bit-in-a-number/
#include <iostream>
#include <stdlib.h>
using namespace std;

// turn of kth bit from right in binary
// representation of n
static int turnOffK(int n, int k) {
    if (k == 0) return n;
    return (n & ~(1 << (k-1)));
}
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout<<"Invalid Arguments, Exiting ...\n";
        return 0;
    }
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    cout<<"n = "<<n<<" k = "<<k<<" turned off "<<k<<"th bit = "<<turnOffK(n,k)<<endl;
}
