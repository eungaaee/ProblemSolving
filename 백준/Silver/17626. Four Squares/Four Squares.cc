#include <iostream>
using namespace std;
int main() {
    int n, *dp;
    cin >> n;
    dp = new int[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = dp[i] > dp[i - j * j] + 1 ? dp[i - j * j] + 1 : dp[i];
        }
    }
    cout << dp[n];
    delete[] dp;
    return 0;
}