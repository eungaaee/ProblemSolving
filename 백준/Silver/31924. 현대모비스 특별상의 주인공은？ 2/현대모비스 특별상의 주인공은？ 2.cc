#include <bits/stdc++.h>
using namespace std;

int N, c;
char board[100][100];

void dfs(int x, int y, char dir, char l) {
    int nx, ny;
    if (dir == 'u') nx = x, ny = y+1;
    else if (dir == 'd') nx = x, ny = y-1;
    else if (dir == 'l') nx = x-1, ny = y;
    else if (dir == 'r') nx = x+1, ny = y;
    else if (dir == 'q') nx = x-1, ny = y+1;
    else if (dir == 'e') nx = x+1, ny = y+1;
    else if (dir == 'z') nx = x-1, ny = y-1;
    else if (dir == 'c') nx = x+1, ny = y-1;
    if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
        if (l == 'M' && board[nx][ny] == 'O') dfs(nx, ny, dir, 'O');
        else if (l == 'O' && board[nx][ny] == 'B') dfs(nx, ny, dir, 'B');
        else if (l == 'B' && board[nx][ny] == 'I') dfs(nx, ny, dir, 'I');
        else if (l == 'I' && board[nx][ny] == 'S') c++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<pair<int, int>> m;
    string row;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> row;
        for (int j = 0; j < N; j++) {
            board[i][j] = row[j];
            if (board[i][j] == 'M') m.push({i, j});
        }
    }
    while (!m.empty()) {
        dfs(m.top().first, m.top().second, 'u', 'M');
        dfs(m.top().first, m.top().second, 'd', 'M');
        dfs(m.top().first, m.top().second, 'l', 'M');
        dfs(m.top().first, m.top().second, 'r', 'M');
        dfs(m.top().first, m.top().second, 'q', 'M');
        dfs(m.top().first, m.top().second, 'e', 'M');
        dfs(m.top().first, m.top().second, 'z', 'M');
        dfs(m.top().first, m.top().second, 'c', 'M');
        m.pop();
    }
    cout << c;
    return 0;
}