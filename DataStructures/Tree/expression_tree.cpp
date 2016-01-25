#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct ExpressionTree {
	char expr;
	ExpressionTree *left, *right;
	ExpressionTree(char opr) : expr(opr) {
		left = NULL;
		right = NULL;
	}
};

bool isOperator(char opr) {
	return opr == '+' || opr == '-' || opr == '*'
	|| opr == '/' || opr == '%' || opr == '^';
}

void inOrder(ExpressionTree *node) {
    if (!node) return;
	inOrder(node->left);
	cout<<node->expr<<" ";
	inOrder(node->right);
}

ExpressionTree* buildTree(string postfix) {
	stack<ExpressionTree*> s;
	ExpressionTree *node, *t1, *t2;
	for (int i = 0; i < postfix.size(); i++) {
		if (!isOperator(postfix[i])) {
			s.push(new ExpressionTree(postfix[i]));
		} else {
			node = new ExpressionTree(postfix[i]);
			node->right = s.top();
			s.pop();
			node->left = s.top();
			s.pop();
			s.push(node);
		}
	}
	ExpressionTree *result = s.top();
	s.pop();
	return result;
}

int main() {
	string postfix = "ab+ef*g*-";
	ExpressionTree *expressionTree = buildTree(postfix);
	inOrder(expressionTree);

	return 0;
}
