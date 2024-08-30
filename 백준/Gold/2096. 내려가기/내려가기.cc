#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, board[3], maxDp[2][3]{}, minDp[2][3]{};
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> board[0] >> board[1] >> board[2];
        maxDp[1][0] = board[0] + max(maxDp[0][0], maxDp[0][1]);
        maxDp[1][1] = board[1] + max({maxDp[0][0], maxDp[0][1], maxDp[0][2]});
        maxDp[1][2] = board[2] + max(maxDp[0][1], maxDp[0][2]);
        minDp[1][0] = board[0] + min(minDp[0][0], minDp[0][1]);
        minDp[1][1] = board[1] + min({minDp[0][0], minDp[0][1], minDp[0][2]});
        minDp[1][2] = board[2] + min(minDp[0][1], minDp[0][2]);
        for (int i = 0; i < 3; i++) {
            maxDp[0][i] = maxDp[1][i];
            minDp[0][i] = minDp[1][i];
        }
    }
    cout << max({maxDp[1][0], maxDp[1][1], maxDp[1][2]}) << ' '
    << min({minDp[1][0], minDp[1][1], minDp[1][2]});
    return 0;
}