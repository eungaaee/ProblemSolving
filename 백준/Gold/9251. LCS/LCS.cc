#include <bits/stdc++.h>
using namespace std;

string A, B;
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B;
    for (int i = 1; i <= A.length(); i++) {
        for (int j = 1; j <= B.length(); j++) {
            if (B[j-1] == A[i-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[A.length()][B.length()];
    return 0;
}