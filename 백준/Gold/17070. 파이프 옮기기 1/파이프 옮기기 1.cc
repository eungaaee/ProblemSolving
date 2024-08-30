#include <bits/stdc++.h>
using namespace std;

int N, house[16][16], cnt;

void dp(int y, int x, int heading) {
    if (x == N-1 && y == N-1) {
        cnt++;
        return;
    }
    if (heading == 0) { // 가로
        if (x+1<N && !house[y][x+1]) {
            house[y][x+1] = -1;
            dp(y, x+1, 0);
            house[y][x+1] = 0;
            if (y+1<N && !house[y+1][x] && !house[y+1][x+1])
                dp(y+1, x+1, 2);
        }
    } else if (heading == 1) { // 세로
        if (y+1<N && !house[y+1][x]) {
            dp(y+1, x, 1);
            if (x+1<N && !house[y][x+1] && !house[y+1][x+1])
                dp(y+1, x+1, 2);
        }
    } else { // 대각선
        if (x+1<N && !house[y][x+1])
            dp(y, x+1, 0);
        if (y+1<N && !house[y+1][x])
            dp(y+1, x, 1);
        if (x+1<N && y+1<N && !house[y][x+1] && !house[y+1][x] && !house[y+1][x+1])
            dp(y+1, x+1, 2);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> house[i][j];
        }
    }
    dp(0, 1, 0);
    cout << cnt;
    return 0;
}