#include<iostream>
using namespace std;

int main() {
    int a = 10, b = 10;

    int val = a++ + b++ + b++ + a++;

    cout<<"val = "<<val<<endl;
    cout<<a+ b+ b+ a<<endl;

    return 0;

}
