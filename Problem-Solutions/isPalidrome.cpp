//http://www.geeksforgeeks.org/check-binary-representation-number-palindrome/
#include <iostream>
using namespace std;

static bool isKthBitSet(unsigned int n, unsigned int k) {
    if (k == 0) return false;
    return (n & (1 << (k-1))) ? true : false;
}

static bool isPalidrome(int n) {
    int l = 1;
    int r = sizeof(unsigned int)*8;

    while (l < r) {
        if (isKthBitSet(n, l) != isKthBitSet(n, r))
            return false;
        l++; r--;
    }
    return true;
}

int main() {
    unsigned int n = (1 << 3) + 1;
    cout<<"n = "<<n<<endl
        <<isPalidrome(n)<<endl;
    n = (1 << 31) + 1;
    cout<<"n = "<<n<<endl
        <<isPalidrome(n)<<endl;
    return 0;
}
