/* // 시간초과
#include <iostream>
#include <vector>
using namespace std;

void makeTree(int cur, int prev, vector<int> *Edge, vector<int> *Tree) {
    for (int next : Edge[cur]) {
        if (next == prev) continue;

        Tree[cur].push_back(next);
        makeTree(next, cur, Edge, Tree);
    }
}

int dfs(int cur, vector<int> *Tree) {
    int cnt = 1;

    for (int next : Tree[cur]) {
        cnt += dfs(next, Tree);
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, Q;
    cin >> N >> R >> Q;

    vector<int> Edge[N+1];

    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;

        Edge[U].push_back(V);
        Edge[V].push_back(U);
    }

    vector<int> Tree[N+1];
    makeTree(R, -1, Edge, Tree);

    for (int i = 0; i < Q; i++) {
        int U;
        cin >> U;

        cout << dfs(U, Tree) << '\n';
    }

    return 0;
} */

#include <iostream>
#include <vector>
using namespace std;

int dfs(int prev, int cur, vector<int> *Edge, int *memo) {
    if (memo[cur] > 0) return memo[cur];
    int cnt = 1;

    for (int next : Edge[cur]) {
        if (next == prev) continue;
        cnt += dfs(cur, next, Edge, memo);
    }

    return memo[cur] = cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R, Q;
    cin >> N >> R >> Q;

    vector<int> Edge[N+1];

    for (int i = 0; i < N-1; i++) {
        int U, V;
        cin >> U >> V;

        Edge[U].push_back(V);
        Edge[V].push_back(U);
    }

    int memo[N+1] = {};
    dfs(-1, R, Edge, memo);

    while (Q--) {
        int U;
        cin >> U;

        cout << memo[U] << '\n';
    }

    return 0;
}