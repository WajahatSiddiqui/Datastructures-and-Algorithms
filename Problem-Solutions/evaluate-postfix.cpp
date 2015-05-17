/*
 * This program accepts infix expression, converts into postfix
 * and evaluates based on the precedence of operators.
 */
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <math.h>
#include <vector>
using namespace std;
vector<string> vStrings;
int N, AnswerN;

enum PRIORITY {
	PLUS_MINUS = 1, MULTIPLY_DIVIDE, POWER, BRACES, INVALID = -1
};

static PRIORITY getPriority(char expr) {
	switch (expr) {
	case '+':
	case '-':
		return PLUS_MINUS;
	case '*':
	case '/':
		return MULTIPLY_DIVIDE;
	case '^':
		return POWER;
	case ')':
	case '(':
		return BRACES;
	}
	return INVALID;
}

static void compute(stack<int> &st, char expr) {
    if (st.empty()) return;
	int n1, n2;
	n2 = st.top();
	st.pop();
	n1 = st.top();

	switch(expr) {
	case '+':
			  st.push((n1+n2));
			  break;
	case '-':
			  st.push((n1-n2));
			  break;
	case '*':
			  st.push((n1*n2));
			  break;
	case '/':
			  st.push((n1/n2));
			  break;
	case '^':
			  st.push(pow(n1, n2));
			  break;
	}
}

static int evaluate(int n) {
	stack<int> st;
	int result = 0, number;
	for (int i = 0; i < n; i++) {
		if (isdigit(*vStrings[i].c_str())) {
			stringstream ss;
			ss<<vStrings[i];
			ss>>number;
			st.push(number);
		} else {
			compute(st, *vStrings[i].c_str());
		}
	}
	result = st.top();
	st.pop();
	return result;
}

int main() {
	int test_cases;
	freopen("evaluate-postfix.txt", "r", stdin);
	cin>>test_cases;
	string input;
	for (int t = 1; t <= test_cases; t++) {
		cin>>N;
		for (int i = 0; i < N; i++) {
			cin>>input;
			vStrings.push_back(input);
		}
		AnswerN = evaluate(N);
		cout<<"#"<<t<<" "<<AnswerN<<endl;
		vStrings.clear();
	}
	return 0;
}
