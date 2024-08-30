#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, c{}, *dp;
    string s;
    cin >> n >> m >> s;
    dp = new int[m];
    dp[0] = s[0] == 'I' ? 1 : -1;
    dp[1] = s[1] == 'I' ? 1 : -1;
    for (int i = 2; i < m; i++) {
        if (s[i] == 'I') {
            if (dp[i - 1] == -1 && dp[i - 2] > 0) {
                dp[i] = dp[i - 2] + 1;
            } else {
                dp[i] = 1;
            }
        } else {
            dp[i] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        if (dp[i] > n) {
            c++;
        }
    }
    cout << c;
    return 0;
}