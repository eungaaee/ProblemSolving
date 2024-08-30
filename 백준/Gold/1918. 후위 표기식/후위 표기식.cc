#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string infix;
    stack<char> ops;
    char cur;
    cin >> infix;

    for (int i = 0; i < infix.size(); i++) {
        cur = infix[i];
        if (cur == '*' || cur == '/') {
            if (ops.empty() || ops.top() == '*' || ops.top() == '/') {
                while (!ops.empty() && ops.top() != '(' && ops.top() != '+' && ops.top() != '-') cout << ops.top(), ops.pop();
            }
            ops.push(cur);
        } else if (cur == '(') {
            ops.push(cur);
        } else if (cur == ')') {
            while (ops.top() != '(') cout << ops.top(), ops.pop();
            ops.pop();
        } else if (cur == '+' || cur == '-') {
            if (ops.empty() || ops.top() == '*' || ops.top() == '/' || ops.top() == '+' || ops.top() == '-') {
                while (!ops.empty() && ops.top() != '(') cout << ops.top(), ops.pop();
                ops.push(cur);
            } else {
                ops.push(cur);
            }
        } else cout << cur;
    }
    while (!ops.empty()) cout << ops.top(), ops.pop();
    return 0;
}