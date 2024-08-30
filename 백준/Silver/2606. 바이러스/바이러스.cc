#include <iostream>
using namespace std;
int dfs(int n, int **arr, int idx) {
    static int c = 0;
    for (int i = 0; i < n; i++) {
        if (arr[idx][i] == 1) {
            c++;
            for (int j = 0; j < n; j++) {
                arr[j][i] = 2;
            }
            dfs(n, arr, i);
        }
    }
    return c;
}
int main() {
    int n, m, **computers, t1, t2;
    cin >> n >> m;
    computers = new int *[n];
    for (int i = 0; i < n; i++) {
        computers[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        computers[t1 - 1][t2 - 1] = 1;
        computers[t2 - 1][t1 - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        computers[i][0] = 2;
    }
    cout << dfs(n, computers, 0);
    delete[] computers;
    return 0;
}