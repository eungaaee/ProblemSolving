#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, A, B, C;
    vector<pair<int, int>> bus[501];
    long long dist[501];
    for (int i = 1; i <= 500; i++) dist[i] = INF;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        bus[A].push_back({B, C});
    }
    dist[1] = 0;
    int nxt, ncost;
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < bus[i].size(); j++) {
                nxt = bus[i][j].first;
                ncost = bus[i][j].second;
                if (dist[i] < INF && dist[nxt] > dist[i]+ncost) {
                    if (k == N) {
                        cout << -1;
                        return 0;
                    } else 
                        dist[nxt] = dist[i]+ncost;
                }
            }
        }
    }
    for (int i = 2; i <= N; i++)
        cout << (dist[i] < INF ? dist[i] : -1) << '\n';
    return 0;
}