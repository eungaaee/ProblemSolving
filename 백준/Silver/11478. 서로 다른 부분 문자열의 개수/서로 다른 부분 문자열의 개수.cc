#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<string> strset;
    string s, tmp;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        tmp = "";
        for (int j = i; j < s.size(); j++) {
            tmp += s[j];
            strset.insert(tmp);
        }
    }
    cout << strset.size();
    return 0;
}