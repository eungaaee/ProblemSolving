#include <bits/stdc++.h>
using namespace std;

int N, dp[22];
string str;

int main() {
    cin >> N >> str;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= 21; i++) dp[i] = dp[i-1]+dp[i-2];

    int streak = 0, ans = 1;
    for (int i = 3; i < N;) {
        if (str.substr(i-3, 4) == "long") streak++, i += 4;
        else ans *= dp[streak], streak = 0, i++;
    }
    ans *= dp[streak];
    cout << ans;
    return 0;
}