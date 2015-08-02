#include<iostream>
#include<math.h>
using namespace std;

int toBinary(int dec) {
    int bin = 0, i = 0;
    while (dec) {
        bin = bin + dec%2*pow(10,i);
        i++;
        dec >>= 1;
    }
    return bin;
}

int toBase4(int dec) {
    int base4 = 0, i = 0;
    while (dec) {
        base4 = base4 + dec%4*pow(10,i);
        i++;
        dec >>= 2;
    }
    return base4;
}

int toOctal(int dec) {
    int octal = 0, i = 0;
    while (dec) {
        octal = octal + dec%8*pow(10,i);
        i++;
        dec >>= 3;
    }
    return octal;
}


int main() {
    cout<<"11 in binary is: "<<toBinary(11)<<endl;
    cout<<"11 in base4 is : "<<toBase4(11)<<endl;
    cout<<"11 in octal is : "<<toOctal(11)<<endl;
    return 0;
}

