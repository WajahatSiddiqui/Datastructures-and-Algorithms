#include <iostream>
using namespace std;

/**
 * T(N) = O(N), N no. of bits in integer
 */
int countDecimal(int n) {
    int count = 0;
    while (n) {
        if (n % 2 == 1) count++;
        n = n/2;
    }
    return count;
}


/**
 * T(N) = O(N), N no. of bits in integer
 */
int countBinary(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}


/**
 * n-1 will reset the bits upto set bit
 * n = n & n-1 will reset the bit in n
 * that implies we only need to run the loop
 * with no. of set bits
 * T(N) = O(LogN), N no. of bits in integer
 */
int countSetBits(unsigned int n) {
    int count = 0;
    while (n) {
        n &= n-1;
        count++;
    }
    return count;
}

int main() {
    cout<<"No. of onces in binary 1011: "<<countDecimal(11)<<endl;
    cout<<"No. of onces in binary 1011: "<<countBinary(11)<<endl;
    cout<<"No. of onces in binary 1011: "<<countSetBits(11)<<endl;
    return 0;
}
