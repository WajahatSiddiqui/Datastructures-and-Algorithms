#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(long long N) {
    if (N <= 1) return false;
    int sqrtN = sqrtl(N);
    for (int i = 2; i <= sqrtN; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T=1;
    long long N;
    //cin>>T;
    while (T--) {
        cin>>N;
        if (isPrime(N)) cout<<"Prime\n";
        else cout<<"Not prime\n";
    }
    return 0;
}
