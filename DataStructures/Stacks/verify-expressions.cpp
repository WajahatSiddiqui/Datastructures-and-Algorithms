/**
 * This program verfies given mathematical expression
 * using stack.
 * I/P: (A+B)*(C+D)
 * O/P: true
 * I/P: (A+B)*(C+D
 * O/P: false
 */
#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

/**
 * verifies expression by using stack
 * Algorithm:
 * (1) input has open symbols (/{/[ push
 * (2) input has operands keep going
 * (3) input has close symbols )/}/] =>
 * check the top element has the opposite, 
 * pop if it is true
 * (4) continue above all untill end of input.
 * T(n) = O(n)
 * S(n) = O(n) for stack
 */
static bool verifyExpression(const char *expr) {
    stack<char> st;
    while (*expr != '\0') {
        switch(*expr) {
            case '(':
            case '{':
            case '[':
                st.push(*expr);
                break;
            case ')':
                if ((char)st.top() == '(')
                    st.pop();
                    break;
            case '}':
                if ((char)st.top() == '{')
                    st.pop();
                    break;
            case ']':
                if ((char)st.top() == '[')
                    st.pop();
                    break;
        }
        expr++;
    }
    // elements are not popped
    // as per the sequence
    if (!st.empty())
        return false;
    return true;
}

int main() {
    string expr;
    int test_cases;
    freopen("verify-expressions.txt", "r", stdin);
    cin>>test_cases;
    for (int i = 1; i <= test_cases; i++) {
        cin>>expr;
        cout<<"#"<<i<<" :"<<expr<<"\t";
    if (!expr.empty() && verifyExpression(expr.c_str()))
        cout<<"Expression is valid\n";
    else
        cout<<"Expression is invalid\n";
    expr.clear();
    }
    return 0;
}
