#include <bits/stdc++.h>
using namespace std;

int N, K, depth = -1, way = 0;
bool v[100001];
queue<int> q;

void bfs() {
    int cur, qsize;
    while (!q.empty()) {
        depth++;
        qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            cur = q.front();
            q.pop();
            v[cur] = 1;
            if (cur == K) way++;
            if (cur-1 >= 0 && !v[cur-1]) q.push(cur-1);
            if (cur+1 <= 100000 && !v[cur+1]) q.push(cur+1);
            if (cur*2 <= 100000 && !v[cur*2]) q.push(cur*2);
        }
        if (way) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    if (N >= K) {
        cout << N-K;
        cout << "\n1";
        return 0;
    }
    v[N] = 1;
    q.push(N);
    bfs();
    cout << depth << '\n' << way;
    return 0;
}