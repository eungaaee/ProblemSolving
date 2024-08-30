#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, N, S, E, ans;
    cin >> T;
    while (T--) {
        cin >> N >> S >> E;
        if (S == 1 && E == N) ans = 0;
        else if (S == N && E == 1) ans = 0;
        else if (S == 1 || S == N) ans = 1;
        else if (S+1 == E || S-1 == E) ans = 1;
        else ans = 2;
        cout << ans << '\n';
    }
    return 0;
}