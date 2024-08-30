#include <memory.h>

#include <iostream>
using namespace std;
int n, dx, dy;
char grid[100][100], rgb;
bool v[100][100];
void dfs(int x, int y, bool rg) {
    const static int d[4]{0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        dx = x + d[i];
        dy = y + d[3 - i];
        if (dx >= 0 && dx < n && dy >= 0 && dy < n && !v[dx][dy]) {
            if (rg) {
                if (grid[dx][dy] == rgb || (grid[dx][dy] == 'R' && rgb == 'G') || (grid[dx][dy] == 'G' && rgb == 'R')) {
                    v[dx][dy] = 1;
                    dfs(dx, dy, 1);
                }
            } else {
                if (grid[dx][dy] == rgb) {
                    v[dx][dy] = 1;
                    dfs(dx, dy, 0);
                }
            }
        }
    }
}
int main() {
    int c{};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!v[i][j]) {
                v[i][j] = 1;
                rgb = grid[i][j];
                dfs(i, j, 0);
                c++;
            }
        }
    }
    cout << c << ' ';
    c = 0;
    for (int i = 0; i < n; i++)
        memset(v[i], 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!v[i][j]) {
                v[i][j] = 1;
                rgb = grid[i][j];
                dfs(i, j, 1);
                c++;
            }
        }
    }
    cout << c;
    return 0;
}