#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int N, K, dist[100001];
deque<int> dq;

int bfs() {
    int cur;
    while (!dq.empty()) {
        cur = dq.front();
        dq.pop_front();
        if (cur*2 == K)
            return dist[cur];
        else if (cur-1 == K || cur+1 == K)
            return dist[cur] + 1;

        if (cur*2 <= 100000 && dist[cur*2] == INF) {
            dist[cur*2] = dist[cur];
            dq.push_front(cur*2);
        }
        if (cur-1 >= 0 && dist[cur-1] == INF) {
            dist[cur-1] = dist[cur]+1;
            dq.push_back(cur-1);
        }
        if (cur+1 <= 100000 && dist[cur+1] == INF) {
            dist[cur+1] = dist[cur]+1;
            dq.push_back(cur+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    if (N >= K) {
        cout << N - K;
        return 0;
    }
    for (int i = 0; i <= 100000; i++) dist[i] = INF;
    dist[N] = 0;
    dq.push_back(N);
    cout << bfs();
    return 0;
}