#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, N, M;
    long long ans, d;
    cin >> T;
    while (T--) {
        ans = 1, d = 1;
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            ans *= M;
            d *= i;
            if (ans % d == 0) ans /= d, d = 1;
            M--;
        }
        cout << ans / d << '\n';
    }
    return 0;
}