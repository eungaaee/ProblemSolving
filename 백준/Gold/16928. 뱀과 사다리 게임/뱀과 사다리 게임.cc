#include <iostream>
#include <queue>
using namespace std;
int board[100], cur, c;
queue<pair<int, int>> q;
void bfs() {
    while (!q.empty()) {
        cur = q.front().first;
        c = q.front().second;
        q.pop();
        if (board[cur] > 0)
            cur = board[cur];
        for (int i = 1; i <= 6; i++) {
            if (cur + i == 99) {
                c += 1;
                return;
            }
            if (board[cur + i] >= 0)
                q.push({cur + i, c + 1});
            if (board[cur + i] == 0)
                board[cur + i] = -1;
        }
    }
}
int main() {
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        cin >> a >> b;
        board[a - 1] = b - 1;
    }
    q.push({0, 0});
    bfs();
    cout << c;
    return 0;
}