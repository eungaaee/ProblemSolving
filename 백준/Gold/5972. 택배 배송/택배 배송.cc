#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> barn[N+1];

    for (int i = 0, A, B, C; i < M; i++) {
        cin >> A >> B >> C;
        barn[A].push_back({C, B});
        barn[B].push_back({C, A});
    }

    int dist[N+1];
    for (int i = 1; i <= N; i++) dist[i] = INF;
    bool visited[N+1] = {};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (visited[cur]) continue;
        else visited[cur] = true;

        for (auto i: barn[cur]) {
            if (cost + i.first < dist[i.second]) {
                dist[i.second] = cost + i.first;
                pq.push({dist[i.second], i.second});
            }
        }
    }

    cout << dist[N];

    return 0;
}