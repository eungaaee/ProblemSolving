#include <memory.h>

#include <iostream>
using namespace std;
int n;
bool dfs(bool **linked, int x) {
    bool isGo = 0;
    for (int i = 0; i < n; i++) {
        if (linked[x][i]) {
            for (int j = 0; j < n; j++) {
                linked[j][i] = 0;
            }
            isGo = 1;
            dfs(linked, i);
        }
    }
    return isGo ? 1 : 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, u, v, c{};
    bool **linked, isOnly;
    cin >> n >> m;
    linked = new bool *[n];
    for (int i = 0; i < n; i++)
        linked[i] = new bool[n];
    for (int i = 0; i < n; i++) {
        memset(linked[i], false, n);
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        linked[u - 1][v - 1] = 1;
        linked[v - 1][u - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        isOnly = true;
        for (int j = 0; j < n; j++) {
            if (linked[i][j] == 1) {
                isOnly = false;
                break;
            }
        }
        if (isOnly) c++;
    }
    for (int i = 0; i < n; i++) {
        linked[i][0] = 0;
    }
    for (int i = 0; i < n; i++) {
        c += dfs(linked, i);
    }
    cout << c;
    for (int i = 0; i < n; i++)
        delete[] linked[i];
    delete[] linked;
    return 0;
}