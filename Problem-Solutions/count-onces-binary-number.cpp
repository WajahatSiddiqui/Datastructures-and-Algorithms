#include <iostream>
using namespace std;

int countDecimal(int n) {
    int count = 0;
    while (n) {
        if (n % 2 == 1) count++;
        n = n/2;
    }
    return count;
}

int countBinary(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    cout<<"No. of onces in binary 1011: "<<countBinary(11)<<endl;
    return 0;
}
