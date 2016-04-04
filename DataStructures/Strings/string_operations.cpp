#include <iostream>
#include <string>
using namespace std;

void removeDuplicates(string& str) {
	int i, j;
	string dups;
	for (i = 1, j = 0; str[i] != '\0'; i++) {
		if (str[i-1] != str[i]) {
			dups.push_back(str[i-1]);
		}
	}
	dups.push_back(str[i-1]);
	str = dups;	
}

void reverse(string& str) {
	int left = 0, right = str.length()-1;
	char c;
	while (left <= right) {
		c = str[left];
		str[left] = str[right];
		str[right] = c;
		left++;
		right--;
	}
}

int length(string& str) {
	int count = 0;
	while (str[count++] != '\0');
	return count-1;
}

int length_rec(const char *str) {
	if (str == NULL || *str == '\0') return 0;
	return 1 + length_rec(str+1);
}

void copy(string &src, string &destn) {
	int left = 0, right = src.length();
	while(left != right) {
		destn.push_back(src[left++]);
	}
}

int matches(string &str, char c) {
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c) return i;
	return -1;
}

/**
 * To find if a string s2 is rotation of s1
 * Both the string length has to be same
 * (i) concat = s2 + s2
 * (ii) find s1 in concat 
 * if s1 is found the s2 is rotation of s1
 * Why this is correct because 
 * s1 = abcd s2 = 
 */
bool isRotated(string &str1, string& str2) {
	if (str1.length() != str2.length()) return false;
	string concat = str2 + str2;
	return concat.find(str1) != string::npos;
}

int main() {
	string str = "aabbbbccccdeffff";
	removeDuplicates(str);
	cout<<"Remove Duplicates: "<<str<<endl;
	reverse(str);
	cout<<"After reversing: "<<str<<endl;
	cout<<"length of str: "<<length(str)<<endl;
	cout<<"length of str(recursive): "<<length_rec(str.c_str())<<endl;
	string copyStr;
	copy(str, copyStr);
	cout<<"After copying: "<<copyStr<<endl;
	cout<<"Matching d in str: "<<matches(str, 'd')<<endl;
	cout<<"Matching z in str: "<<matches(str, 'z')<<endl;
	string str1 = "treehouse", str2 = "eehouse";
	if (isRotated(str1, str2)) {
		cout<<str2<<" is rotation of "<<str1<<endl;
	} else {
		cout<<str2<<" is not rotated of "<<str1<<endl;
	}
	return 0;
}