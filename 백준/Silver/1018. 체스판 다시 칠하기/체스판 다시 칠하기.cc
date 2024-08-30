#include <iostream>
using namespace std;
int main() {
    int n, m, c1, c2, minc{64};
    char a[50][51];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            c1 = 0;
            c2 = 0;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if ((i + k + j + l) % 2 == 0 && a[i + k][j + l] == 'W' || (i + k + j + l) % 2 == 1 && a[i + k][j + l] == 'B') {
                        c1++;
                    }
                }
            }
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if ((i + k + j + l) % 2 == 0 && a[i + k][j + l] == 'B' || (i + k + j + l) % 2 == 1 && a[i + k][j + l] == 'W') {
                        c2++;
                    }
                }
            }
            minc = c1 < c2 ? c1 < minc ? c1 : minc : c2 < minc ? c2 : minc;
        }
    }
    cout << minc;
    return 0;
}