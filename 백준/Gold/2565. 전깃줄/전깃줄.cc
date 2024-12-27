#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    pair<int, int> line[N];
    for (int i = 0; i < N; i++) {
        cin >> line[i].first >> line[i].second;
    }
    sort(line, line+N);

    // 시작점 순으로 정렬한 다음, 도착점들의 LIS 구하기
    int dp[N+1], end = 0;
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        int cur = line[i].second;

        if (cur > dp[end]) dp[++end] = cur;
        else if (cur < dp[end]) *lower_bound(dp, dp+end, cur) = cur;
    }

    cout << N - end;

    return 0;
}