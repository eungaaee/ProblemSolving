#include <memory.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, **map, *houses;
void dfs(int x, int y, int c) {
    const static int d[4]{0, 0, -1, 1};
    if (map[x][y] == 0) return;
    map[x][y] = 0;
    houses[c]++;
    for (int i = 0; i < 4; i++) {
        if (x + d[i] >= 0 && y + d[3 - i] >= 0 && x + d[i] < n && y + d[3 - i] < n) {
            dfs(x + d[i], y + d[3 - i], c);
        }
    }
}
int main() {
    int complex{};
    string line;
    cin >> n;
    map = new int*[n];
    houses = new int[n * n];
    memset(houses, 0, 4 * n * n);
    for (int i = 0; i < n; i++) {
        map[i] = new int[n];
        cin >> line;
        for (int j = 0; j < n; j++) {
            map[i][j] = line[j] - 48;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                dfs(i, j, complex);
                complex++;
            }
        }
    }
    sort(houses, houses + complex);
    cout << complex;
    for (int i = 0; i < complex; i++) {
        if (houses[i] > 0) {
            cout << '\n'
                 << houses[i];
        }
    }
    for (int i = 0; i < n; i++) delete[] map[i];
    delete[] map;
    delete[] houses;
    return 0;
}