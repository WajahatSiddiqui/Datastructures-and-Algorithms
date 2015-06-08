/**
 * Program to determine if the machine is big/little endian
 * Big endian, MSB is stored as lowest address: Motorola
 * Little endian, LSB is stored as lowest address : Intel, Arm
 * http://www.geeksforgeeks.org/little-and-big-endian-mystery/
 */
#include <iostream>
using namespace std;

/**
 * Method1
 * Returns true if machine is big endian, false otherwise
 */
bool endianness1() {
    int var = 1;
    char *ptr = (char*) &var;
    // deref to get the lowest address;
    // if the deref pointer is 1 then machine is little endian
    // else if the deref pointer is 0 then machine is big endian
    return *ptr;
}

/**
 * Method 2 using Union
 */
bool endianness2() {
    union endianType {
        int var;
        char chr;
    } type;
    type.var = 1;
    return type.chr;
}

int main() {
    if (endianness2())
        cout<<"Little Endian\n";
    else
        cout<<"Big Endian\n";
    return 0;
}
