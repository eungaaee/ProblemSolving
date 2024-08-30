#include <bits/stdc++.h>
using namespace std;

int N, K, depth = 0, path[100001];
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
            if (cur-1 >= 0 && !v[cur - 1]) {
                v[cur-1] = 1;
                path[cur-1] = cur;
                q.push(cur-1);
            }
            if (cur+1 <= 100000 && !v[cur + 1]) {
                v[cur+1] = 1;
                path[cur+1] = cur;
                q.push(cur+1);
            }
            if (cur*2 <= 100000 && !v[cur * 2]) {
                v[cur*2] = 1;
                path[cur*2] = cur;
                q.push(cur*2);
            }
            if (cur-1 == K || cur+1 == K || cur*2 == K) return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    if (N >= K) {
        cout << N - K << '\n';
        for (int i = N; i >= K; i--) cout << i << ' ';
        return 0;
    }

    q.push(N);
    bfs();
    cout << depth << '\n';
    stack<int> reverse;
    int t = K;
    for (int i = 0; i < depth+1; i++) {
        reverse.push(t);
        t = path[t];
    }
    for (int i = 0; i < depth+1; i++) {
        cout << reverse.top() << ' ';
        reverse.pop();
    }
    return 0;
}