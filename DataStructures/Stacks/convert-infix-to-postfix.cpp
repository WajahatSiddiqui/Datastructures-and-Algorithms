/**
 * Program to convert infix expression to postfix
 * I/P: A+B-C
 * O/P: AB+C-
 * I/P: A*B-(C+D)+E
 * O/P: AB*CD+-E+
 */
#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

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
    case ']':
    case '[':
        return BRACES;
    }
    return INVALID;
}

/**
 * converts infix expression into postfix using stack
 * T(n) = O(n)
 * S(n) = O(n) for stack
 */
static string toPostFixExpr(const char *infix_expr) {
    stack<char> st;
    string result = "";
    while(*infix_expr != '\0') {
        switch(*infix_expr) {
                case '(':
                case '[':
                        st.push(*infix_expr);
                         break;
                case ')':
                case ']':
                          while(!st.empty() && (st.top() != '(' && st.top() != '[')) {
                              result = result + st.top();
                              st.pop();
                          }
                          if (!st.empty() && (st.top() =='(' || st.top() == '['))
                              st.pop();
                          break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (!st.empty() && 
                            (st.top() != '(' && st.top() != '[') && 
                            getPriority(st.top()) >= getPriority(*infix_expr)) {
                        result = result + st.top();
                        st.pop();
                    }
                    st.push(*infix_expr);
                    break;
                default: result = result + *infix_expr;
            }
        infix_expr++;
    }
    while (!st.empty()) {
        result = result + st.top();
        st.pop();
    }
    return result;
}

int main() {
    string expr;
    int test_cases;
    freopen("convert-infix-to-postfix.txt", "r", stdin);
    cin>>test_cases;
    for (int i = 1; i <= test_cases; i++) {
        cin>>expr;
        cout<<"#"<<i<<" :"<<expr<<"\t\t";
        cout<<toPostFixExpr(expr.c_str())<<endl;
        expr.clear();
    }
    return 0;
}
