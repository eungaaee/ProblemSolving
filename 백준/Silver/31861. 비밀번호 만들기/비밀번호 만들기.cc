#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, cnt, dp[1001][26] = {};
    cin >> N >> M;

    for (int i = 0; i < 26; i++) dp[1][i] = 1;

    for (int i = 2; i <= M; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (j - k >= N || k - j >= N) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = (ans + dp[M][i]) % MOD;
    cout << ans;
    return 0;
}