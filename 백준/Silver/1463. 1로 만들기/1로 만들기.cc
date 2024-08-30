#include <iostream>
using namespace std;
int main() {
    int n, c = 0, *dp;
    cin >> n;
    dp = new int[n+1];
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;  // 2or3으로 나누어지지 않을 때(1 더하는 경우)
        if (i % 2 == 0) {       // 2로 나누어질 떄
            dp[i] = dp[i] > dp[i / 2] + 1 ? dp[i / 2] + 1 : dp[i];
        }
        if (i % 3 == 0) {  // 3으로 나누어질 때
            dp[i] = dp[i] > dp[i / 3] + 1 ? dp[i / 3] + 1 : dp[i];
        }
    }
    cout << dp[n];
    delete[] dp;
    return 0;
}