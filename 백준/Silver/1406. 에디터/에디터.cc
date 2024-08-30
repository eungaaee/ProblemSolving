// stack
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> l, r;
    char S[100001];
    int M;
    cin >> S >> M;
    for (int i = 0; S[i] != '\0'; i++) l.push(S[i]);

    char o1, o2;
    while (M--) {
        cin >> o1;
        if (o1 == 'L') {
            if (!l.empty()) r.push(l.top()), l.pop();
        } else if (o1 == 'D') {
            if (!r.empty()) l.push(r.top()), r.pop();
        } else if (o1 == 'B') {
            if (!l.empty()) l.pop();
        } else {
            cin >> o2;
            l.push(o2);
        }
    }

    stack<char> t;
    while (!l.empty()) t.push(l.top()), l.pop();
    while (!t.empty()) cout << t.top(), t.pop();
    while (!r.empty()) cout << r.top(), r.pop();
    
    return 0;
}