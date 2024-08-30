#include <iostream>
using namespace std;
int table[1025][1025];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> table[i][j];
            if (i==0 && j==0) continue;
            else if (i==0) table[i][j] += table[i][j-1];
            else if (j==0) table[i][j] += table[i-1][j];
            else table[i][j] += table[i-1][j] + table[i][j-1] - table[i-1][j-1]; 
        }
    }
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2, ans;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1==0 && y1==0) ans = table[x2][y2];
        else if (x1==0) ans = table[x2][y2] - table[x2][y1-1];
        else if (y1==0) ans = table[x2][y2] - table[x1-1][y2];
        else ans = table[x2][y2]-table[x2][y1-1]-table[x1-1][y2]+table[x1-1][y1-1];
        cout << ans << '\n';
    }
    return 0;
}