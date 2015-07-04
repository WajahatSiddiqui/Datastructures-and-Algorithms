// Addition to two numbers using bitwise operators

#include<iostream>
#include<stdlib.h>
using namespace std;

// Truth Table:
// x    y       add     carry
// 0    0       0       0
// 0    1       1       0
// 1    0       1       0
// 1    1       0       1
// add = x ^ y
// carry = x . y

// iterative
static int addition(int x, int y) {
    // iterate until y becomes 0
    while(y != 0) {
        int carry = (x) & y;
        x = x ^ y;
        // carry is shifted by 1 so that adding it
        // to x gives the required result
        y = carry << 1;
    }
    return x;
}

// recursive
static int add(int x, int y) {
    if (y == 0) return x;
    return add((x ^ y), (x & y) << 1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout<<"Error invalid arguments exiting";
        return 0;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    cout<<x<<" + "<<y<<" = "<<add(x, y)<<endl;
    return 0;
}
