#include <iostream>
using namespace std;
int n, m, **paper, maxSum;
bool **visit;
void dfs(int x, int y, int streak, int sum) {
    int nx, ny, minNum{0x3f3f3f3f}, uSum{paper[x][y]};
    const static int d[4]{0, 0, -1, 1};
    if (streak == 4) {
        if (sum > maxSum)
            maxSum = sum;
        return;
    }
    for (int i = 0; i < 4; i++) {
        nx = x + d[i];
        ny = y + d[3 - i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            minNum = 0;
            continue;
        }
        uSum += paper[nx][ny];
        if (paper[nx][ny] < minNum)
            minNum = paper[nx][ny];
        if (!visit[nx][ny]) {
            visit[nx][ny] = 1;
            dfs(nx, ny, streak + 1, sum + paper[nx][ny]);
            visit[nx][ny] = 0;
        }
    }
    if (uSum - minNum > maxSum)
        maxSum = uSum - minNum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    paper = new int *[n];
    visit = new bool *[n];
    for (int i = 0; i < n; i++) {
        paper[i] = new int[m];
        visit[i] = new bool[m];
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visit[i][j] = 1;
            dfs(i, j, 1, paper[i][j]);
            visit[i][j] = 0;
        }
    }
    cout << maxSum;
    return 0;
}