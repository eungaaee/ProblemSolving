#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, bus[101][101];
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++)
            bus[i][j] = i == j ? 0 : INF;
    }
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (c < bus[a][b]) bus[a][b] = c;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (bus[i][j] > bus[i][k] + bus[k][j])
                    bus[i][j] = bus[i][k] + bus[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << (bus[i][j] < INF ? bus[i][j] : 0) << ' ';
        cout << '\n';
    }
    return 0;
}