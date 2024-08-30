#include <memory.h>
#include <iostream>
using namespace std;
int n;
bool **G, *visit;
void dfs(int x) {
    for (int i = 0; i < n; i++) {
        if (G[x][i] && !visit[i]) {
            visit[i] = 1;
            dfs(i);
        }
    }
}
int main() {
    cin >> n;
    G = new bool *[n];
    visit = new bool[n];
    for (int i = 0; i < n; i++) {
        G[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        memset(visit, 0, n);
        dfs(i);
        for (int j = 0; j < n; j++) {
            cout << visit[j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < n; i++) delete[] G[i];
    delete[] G;
    return 0;
}