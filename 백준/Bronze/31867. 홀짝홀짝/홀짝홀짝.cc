#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string K;
    cin >> N >> K;

    int cur, odd = 0, even = 0;
    for (int i = 0; i < N; i++) {
        cur = K[i]-'0';
        if (cur%2) odd++;
        else even++;
    }

    if (even > odd) cout << 0;
    else if (even < odd) cout << 1;
    else cout << -1;
    return 0;
}