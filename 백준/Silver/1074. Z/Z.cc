#include <iostream>
using namespace std;
int r, c, v;
void dfs(int n, int x, int y) {
    if (x == c && y == r) {
        cout << v;
        return;
    }
    if (n == 1) {
        v++;
    } else {
        if (c <= x + n && r <= y + n && c >= x && r >= y) {
            dfs(n >> 1, x, y);
            dfs(n >> 1, x + (n >> 1), y);
            dfs(n >> 1, x, y + (n >> 1));
            dfs(n >> 1, x + (n >> 1), y + (n >> 1));
        } else {
            v += n * n;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N >> r >> c;
    dfs(1 << N, 0, 0);
    return 0;
}