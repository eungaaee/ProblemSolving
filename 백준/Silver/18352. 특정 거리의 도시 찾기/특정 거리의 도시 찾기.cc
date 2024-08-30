#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K, X, A, B;
    cin >> N >> M >> K >> X;
    vector<int> map[N + 1];
    priority_queue<pair<int, int>> pq;
    int dist[N + 1];

    for (int i = 1; i <= N; i++) dist[i] = INF;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        map[A].push_back(B);
    }
    pq.push({0, X});
    dist[X] = 0;
    
    int cost, cur;
    while (!pq.empty()) {
        cost = -pq.top().first;
        cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost) continue;
        for (int i = 0; i < map[cur].size(); i++) {
            if (dist[map[cur][i]] > cost + 1) {
                dist[map[cur][i]] = cost + 1;
                pq.push({-(cost+1), map[cur][i]});
            }
        }
    }

    bool isExist = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            cout << i << '\n';
            isExist = 1;
        }
    }
    if (!isExist) cout << -1;
    return 0;
}