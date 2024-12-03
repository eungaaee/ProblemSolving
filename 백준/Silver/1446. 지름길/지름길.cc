#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<pair<int, int>> shortcut[10001];
    for (int i = 0, from, to, cost; i < N; i++) {
        cin >> from >> to >> cost;
        shortcut[to].push_back({from ,cost});
    }

    int dp[D+1];
    for (int i = 1; i <= D; i++) dp[i] = INF;
    dp[0] = 0;

    for (int i = 1; i <= D; i++) {
        dp[i] = dp[i-1] + 1;
        for (auto path: shortcut[i]) {
            if (dp[path.first] + path.second < dp[i])
                dp[i] = dp[path.first] + path.second;
        }
    }

    cout << dp[D];
    
    return 0;
}