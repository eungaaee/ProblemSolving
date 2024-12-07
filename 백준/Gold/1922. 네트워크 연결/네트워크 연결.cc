#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edge[1001];
    for (int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
        edge[b].push_back({c, a});
    }

    // prim's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool visited[1001] = {};
    int ans = 0;

    visited[1] = true;
    for (auto &i: edge[1]) {
        pq.push(i);
    }

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (visited[cur]) continue;
        else visited[cur] = true;

        ans += cost;
        for (auto &i: edge[cur]) {
            if (!visited[i.second]) pq.push(i);
        }
    }

    cout << ans;

    return 0;
}