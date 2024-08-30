#include <memory.h>

#include <iostream>
#include <queue>
using namespace std;
void dfs(int **graph, bool *isExplr, int n, int v) {
    cout << v + 1 << ' ';
    isExplr[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !isExplr[i]) {
            dfs(graph, isExplr, n, i);
        }
    }
}
void bfs(int **graph, bool *isExplr, int n, int v) {
    queue<int> q;
    q.push(v);
    isExplr[v] = true;
    while (!q.empty()) {
        cout << q.front() + 1 << ' ';
        for (int i = 0; i < n; i++) {
            if (graph[q.front()][i] && !isExplr[i]) {
                q.push(i);
                isExplr[i] = true;
            }
        }
        q.pop();
    }
}
int main() {
    int n, m, v, **graph, a, b;
    bool *isExplr;
    cin >> n >> m >> v;
    graph = new int *[n];
    isExplr = new bool[n];
    memset(isExplr, false, n);
    isExplr[v - 1] = true;
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
        memset(graph[i], 0, 4 * n);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    dfs(graph, isExplr, n, v - 1);
    cout << '\n';
    memset(isExplr, false, n);
    bfs(graph, isExplr, n, v - 1);
    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] isExplr;
    return 0;
}