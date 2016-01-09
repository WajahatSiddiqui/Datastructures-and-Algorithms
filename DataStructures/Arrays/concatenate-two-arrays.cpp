#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int m = 3, n = 2;
	int a1[5] = {1, 2, 3};
	int a2[2] = {4, 5};

	//brute force
	/*int s1 = sizeof(a1)/sizeof(a1[0]);
	int s2 = sizeof(a2)/sizeof(a2[0]);
	cout<<s1<< " "<<s2<<endl;
	for (int i = s1-s2, j = 0; i < s1 && j < s2; i++, j++) a1[i] = a2[j];*/

	// http://man7.org/linux/man-pages/man3/memcpy.3.html
	// without using for loop
	memcpy(a1+m, a2, sizeof(a2));
	for (int i = 0; i < m+n; i++)
		cout<<a1[i]<<" ";
	return 0;
}