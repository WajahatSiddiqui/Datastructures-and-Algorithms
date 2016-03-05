#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int flip_bits(unsigned int N) {
    // convert into 32 bits
    // find the number of digits
    int digits = ((N)?floor( log10(N)/log10(2) ) + 1:0);
    vector<int> binary(digits);
    int i = digits-1;
    while (N != 0) {
        binary[i] = ~(N % 2); // store the flipped binary number
        cout<<binary[i]<<" ";
        N /= 2;
        i--;
    }
    // convert the given number into decimal
    unsigned int decimal = 0;
    int p = binary.size();
    for (int i = 0; i < binary.size(); i++) {
        if (binary[i] == 1)
            decimal += binary[i]* pow(2, p-1);
        p--;
    }
    return decimal;    
}

int main() {
    unsigned x = 0;
    cout << ~x;
    //cout<<flip_bits(1)<<endl;
  
    return 0;
}
