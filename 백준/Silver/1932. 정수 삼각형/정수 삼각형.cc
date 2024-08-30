#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t, tri[501][501], maxSum{0};
    cin >> n;
    cin >> tri[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> t;
            if (j == 1)
                tri[i][j] = t + tri[i - 1][j];
            else if (j < i)
                tri[i][j] = t + max(tri[i - 1][j - 1], tri[i - 1][j]);
            else  // j==i
                tri[i][j] = t + tri[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (tri[n][i] > maxSum)
            maxSum = tri[n][i];
    }
    cout << maxSum;
    return 0;
}