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

int main() {
	string str = "aabbbbccccdeffff";
	removeDuplicates(str);
	cout<<"Remove Duplicates: "<<str<<endl;
	reverse(str);
	cout<<"After reversing: "<<str<<endl;
	cout<<"length of str: "<<length(str)<<endl;
	string copyStr;
	copy(str, copyStr);
	cout<<"After copying: "<<copyStr<<endl;
	cout<<"Matching d in str: "<<matches(str, 'd')<<endl;
	cout<<"Matching z in str: "<<matches(str, 'z')<<endl;
	return 0;
}