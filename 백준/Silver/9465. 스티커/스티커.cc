#include <bits/stdc++.h>
using namespace std;

int dp[100000][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dp[j][i];
            }
        }
        dp[1][0] += dp[0][1];
        dp[1][1] += dp[0][0];
        for (int i = 2; i < n; i++) {
            for (int j = 0; j <= 1; j++) {
                dp[i][j] += max(dp[i-1][!j], dp[i-2][!j]);
            }
        }
        cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
    }
    return 0;
}