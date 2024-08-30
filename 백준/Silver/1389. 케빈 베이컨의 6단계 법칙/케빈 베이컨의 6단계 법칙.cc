// 더 효율적인 플로이드 워셜로 구현.
#include <iostream>
#define INF 1000000000
using namespace std;
int main() {
    int n, m, **friends, kev, minKev{INF}, minIdx;
    cin >> n >> m;
    friends = new int *[n];
    for (int i = 0; i < n; i++) {
        friends[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            friends[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        friends[x - 1][y - 1] = 1;
        friends[y - 1][x - 1] = 1;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (friends[i][j] > friends[i][k] + friends[k][j]) {
                    friends[i][j] = friends[i][k] + friends[k][j];
                }
            }
        }
    }  // ij = min(ij, ik+kj)
    for (int i = 0; i < n; i++) {
        kev = 0;
        for (int j = 0; j < n; j++) {
            kev += friends[i][j];
        }
        if (kev < minKev) {
            minKev = kev;
            minIdx = i;
        }
    }
    cout << minIdx + 1;
    for (int i = 0; i < n; i++)
        delete[] friends[i];
    delete[] friends;
    return 0;
}