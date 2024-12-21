#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string L;
        cin >> L;

        stack<char> left, right;
        for (char& i: L) {
            if (i == '<') {
                if (!left.empty()) {
                    right.push(left.top());
                    left.pop();
                }
            } else if (i == '>') {
                if (!right.empty()) {
                    left.push(right.top());
                    right.pop();
                }
            } else if (i == '-') {
                if (!left.empty()) {
                    left.pop();
                }
            } else {
                left.push(i);
            }
        }

        while (!left.empty()) {
            right.push(left.top());
            left.pop();
        }
        while (!right.empty()) {
            cout << right.top();
            right.pop();
        }

        cout << '\n';
    }

    return 0;
}