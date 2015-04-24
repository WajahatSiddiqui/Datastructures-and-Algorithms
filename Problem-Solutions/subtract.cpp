// Subtracting two numbers using bitwise operators
#include<iostream>
#include<stdlib.h>
using namespace std;

// Truth Table:
// x    y       sub     borrow
// 0    0       0       0
// 0    1       1       1
// 1    0       1       0
// 1    1       0       0
// sub = x ^ y
// borrow = ~x . y

// iterative
static int subtract(int x, int y) {
    // iterate until y becomes 0
    while(y != 0) {
        int borrow = (~x) & y;
        x = x ^ y;
        // borrow is shifted by 1 so that subtracting it
        // from x gives the required result
        y = borrow << 1;
    }
    return x;
}

// recursive
static int sub(int x, int y) {
    if (y == 0) return x;
    return sub((x ^ y), (~x & y) << 1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout<<"Error invalid arguments exiting";
        return 0;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    cout<<x<<" - "<<y<<" = "<<sub(x, y)<<endl;
    return 0;
}
