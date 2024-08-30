#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;
int N, M;
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str;
        m[str] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (m.find(str) == m.end()) continue;
        cnt++;
    }
    cout << cnt;
    return 0;
}