#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string name, log;
    map<string, bool, greater<string>> m;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> name >> log;
        if (log == "enter") m[name] = 1;
        else m.erase(m.find(name));
    }
    for (auto i: m)
        cout << i.first << '\n';
    return 0;
}