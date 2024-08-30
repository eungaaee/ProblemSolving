#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    int c;
    while (cin >> s >> t) {
        c = 0;
        for (int i = 0; i < t.length(); ++i)
            if (s[c] == t[i]) c++;
        if (c == s.size()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}