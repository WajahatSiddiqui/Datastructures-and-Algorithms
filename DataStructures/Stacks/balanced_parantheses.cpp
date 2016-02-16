#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
using namespace std;

bool match(char p1, char p2) {
	return  p1 == '(' && p2 == ')'
	     || p1 == '{' && p2 == '}'
	     || p1 == '[' && p2 == ']';
}

bool isOpenParan(char c) {
	return c == '(' || c == '{' || c == '[';
}

bool isCloseParan(char c) {
	return c == ')' || c == '}' || c == ']';	
}

bool isBalanced(const string& paran) {
	stack<char> s;
	int len = paran.length();
	for (int i = 0; i < len; i++) {
		if (isOpenParan(paran[i])) {
			s.push(paran[i]);
		}

		if (isCloseParan(paran[i])) {
			if (s.empty() || !match(s.top(), paran[i])) return false;
			s.pop();
		}
	}
	// parantheses are left in the stack but input is processed.
	if (!s.empty()) return false;
	return true;
}

int main() {
	int T;
	string paran;
	freopen("balanced_parantheses.txt", "r", stdin);
	cin>>T;
	while (T--) {
		cin>>paran;		
		if (isBalanced(paran))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}