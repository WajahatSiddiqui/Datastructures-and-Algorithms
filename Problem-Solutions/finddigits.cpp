#include <iostream>
#include <cstdio>
using namespace std;

unsigned long findDigits(unsigned long n) {
    int i = 0, count = 0;
    unsigned long N = n;
    int arr[100] = {0};
    while (n != 0) {
        arr[i++] = n % 10;
        n = n / 10;
    }
    for (int j = i-1; j >= 0; j--) {
        if (arr[j] != 0 && N%arr[j] == 0) {
            count++;
        }
    }
    return count;    
}

int main(){
    int t;
    freopen("finddigits.txt", "r", stdin);
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        unsigned long n;
        cin >> n;
        cout<<findDigits(n)<<endl;
    }
    return 0;
}