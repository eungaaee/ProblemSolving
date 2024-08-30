#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[20001];
int visit[20001];

void dfs(int cur, int color) { // 1 = Red, 2 = Blue
    visit[cur] = color;

    for (int i = 0; i < graph[cur].size(); i++) {
        int nxt = graph[cur][i];
        if (!visit[nxt]) dfs(nxt, color^3); // 01xor11 == 10, 10xor11 = 01
    }
}

inline bool isBipartite(int V) {
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (visit[i] == visit[graph[i][j]]) return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    while (K--) {
        int V, E;
        cin >> V >> E;

        int u, v;
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            if (!visit[i]) dfs(i, 1);
        }

        printf(isBipartite(V) ? "YES\n" : "NO\n");

        for (int i = 1; i <= V; i++) {
            graph[i].clear();
            visit[i] = 0;
        }
    }
    return 0;
}