#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, X;
    cin >> N >> M >> X;

    vector<pair<int, int>> m[N+1];
    vector<pair<int, int>> rev_m[N+1];
    int s, e, c;
    for (int i = 0; i < M; i++) {
        cin >> s >> e >> c;
        m[s].push_back({e, c});
        rev_m[e].push_back({s, c});
    }

    int dist[N+1];
    bool sel[N+1];
    for (int i = 1; i <= N; ++i) dist[i] = INF, sel[i] = 0;

    for (int i = 0; i < m[X].size(); i++) dist[m[X][i].first] = m[X][i].second;
    dist[X] = 0, sel[X] = 1;

    int minDist, minIdx;
    for (int k = 0; k < N-1; ++k) {
        minDist = INF;
        for (int i = 1; i <= N; ++i) {
            if (sel[i]) continue;
            if (minDist > dist[i]) minDist = dist[i], minIdx = i;
        }
        sel[minIdx] = 1;
        for (int i = 0; i < m[minIdx].size(); ++i) {
            if (sel[m[minIdx][i].first]) continue;
            if (dist[m[minIdx][i].first] > dist[minIdx] + m[minIdx][i].second)
                dist[m[minIdx][i].first] = dist[minIdx] + m[minIdx][i].second;
        }
    }

    int rev_dist[N+1];
    for (int i = 1; i <= N; ++i) rev_dist[i] = INF, sel[i] = 0;

    for (int i = 0; i < rev_m[X].size(); ++i) rev_dist[rev_m[X][i].first] = rev_m[X][i].second;
    rev_dist[X] = 0, sel[X] = 1;

    for (int k = 0; k < N-1; ++k) {
        minDist = INF;
        for (int i = 1; i <= N; ++i) {
            if (sel[i]) continue;
            if (minDist > rev_dist[i]) minDist = rev_dist[i], minIdx = i;
        }
        sel[minIdx] = 1;
        for (int i = 0; i < rev_m[minIdx].size(); ++i) {
            if (sel[rev_m[minIdx][i].first]) continue;
            if (rev_dist[rev_m[minIdx][i].first] > rev_dist[minIdx] + rev_m[minIdx][i].second)
                rev_dist[rev_m[minIdx][i].first] = rev_dist[minIdx] + rev_m[minIdx][i].second;
        }
    }

    int maxGoBack = 0;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] > 0 && dist[i] < INF && rev_dist[i] > 0 && rev_dist[i] < INF)
            if (maxGoBack < dist[i]+rev_dist[i])
                maxGoBack = dist[i] + rev_dist[i];
    }
    cout << maxGoBack;
    return 0;
}