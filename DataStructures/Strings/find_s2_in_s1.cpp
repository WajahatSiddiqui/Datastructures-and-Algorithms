// http://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
#include <iostream>
#include <string>
#include <limits.h>
#include <vector>
using namespace std;


void findMin(string &s1, string &s2) {
	int len1 = s1.length();
	int len2 = s2.length();
	vector<string> vstr;
	string resStr, ans;
	int i, j = 0, min_len = INT_MAX;
	int visited[256] = {0};

	for (i = 0; i < len2; i++) visited[s2[i]]++;

	for (i = 0; i < len1; i++) {
		resStr.push_back(s1[i]);

		for (int k = 0; k < len2; k++) {
			if (s1[i] == s2[k] && visited[s2[k]]) {
				j++;
				visited[s2[k]]--;
				break;
			}
		}

		if (j == len2) {
			j = 0;
			//cout<<"The string added is: "<<resStr<<endl;
			if (resStr.length() < min_len) {
				int in = resStr.find_first_of(s2[0]);
				if (in != string::npos) {
					resStr = resStr.erase(0, in);
				}
				min_len = resStr.length();
				vstr.push_back(resStr);
				ans = resStr;
				resStr.clear();
				for (int l = 0; l < len2; l++) visited[s2[l]]++;
			}
		}
	}

	cout<<"The min string is \""<<ans<<"\" len = "<<min_len<<endl;
}

int main() {
	string s1 = "this is a test string" ,s2 = "tist";
	findMin(s1, s2);
	return 0;
}
