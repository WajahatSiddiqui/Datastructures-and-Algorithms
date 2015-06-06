/**
 * Reverse a given integer
 */
#include <iostream>
using namespace std;

int reverse(int num) {
    int rev_num = 0;
    while(num != 0) {
        rev_num = rev_num*10 + num%10;
        num = num/10;
    }
    return rev_num;
}

int main() {
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    cout<<"reverse of "<<num<<" : "<<reverse(num)<<endl;
    return 0;
}
