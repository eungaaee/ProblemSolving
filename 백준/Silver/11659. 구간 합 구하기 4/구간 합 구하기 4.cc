#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, i, j, t, *accumulatedNums;
    cin >> n >> m;
    accumulatedNums = new int[n];
    accumulatedNums[0] = 0;
    for (int k = 1; k <= n; k++) {
        cin >> t;
        accumulatedNums[k] = accumulatedNums[k - 1] + t;
    }
    for (int k = 0; k < m; k++) {
        cin >> i >> j;
        cout << accumulatedNums[j] - accumulatedNums[i - 1] << '\n';
    }  // 1 2 3 4 5 -> 1 3 6 10 15
    delete[] accumulatedNums;
    return 0;
}