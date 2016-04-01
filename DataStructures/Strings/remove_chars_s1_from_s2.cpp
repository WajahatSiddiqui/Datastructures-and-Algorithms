// remove chars in s1 which are present in the s2
#include <iostream>
#include <string>
using namespace std;

/**
 * T(n) = O(m+n) m - length of s2 n -length of s1
 */
void removeChars(string &s1, string &s2) {
	int map[256] = {0};
	int s2_len = s2.length();
	for (int i = 0; i < s2_len; i++) {
		map[s2[i]] = 1;
	}
	int s1_len = s1.length();
	string result;
	for (int i = 0; i < s1_len; i++) {
		if (!map[s1[i]]) result.push_back(s1[i]);
	}
	cout<<result<<endl;
}

int main() {
	string s1 = "hello world";
	string s2 = "aeiou";
	removeChars(s1, s2);

	return 0;
}