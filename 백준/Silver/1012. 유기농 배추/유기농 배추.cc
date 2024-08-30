#include <memory.h>

#include <iostream>
using namespace std;
int m, n, c;
int dfs(int **gorang, int x, int y) {
    static const int ndxdy[4] = {0, 0, -1, 1};
    if (gorang[x][y] == 0)
        return 0;
    else
        gorang[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        if (x + ndxdy[i] >= 0 && y + ndxdy[3-i] >= 0 && x + ndxdy[i] < m && y + ndxdy[3-i] < n) {
            dfs(gorang, x + ndxdy[i], y + ndxdy[3-i]);
        }
    }
    return 1;
}
int main() {
    int t, k, **gorang, x, y;
    cin >> t;
    for (int i = 0; i < t; i++) {
        c = 0;
        cin >> m >> n >> k;
        gorang = new int *[m];
        for (int i = 0; i < m; i++) {
            gorang[i] = new int[n];
        }
        for (int i = 0; i < m; i++) {
            memset(gorang[i], 0, 4 * n);
        }
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            gorang[x][y] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                c += dfs(gorang, i, j); //배추 무더기 한 구역 탐색 끝냈을 때 1 반환함.
            }
        }
        cout << c << '\n';
    }
    for (int i = 0; i < m; i++) {
        delete[] gorang[i];
    }
    delete[] gorang;
    return 0;
}