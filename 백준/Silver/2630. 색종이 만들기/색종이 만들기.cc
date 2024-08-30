#include <iostream>
using namespace std;
bool **paper;
int cw, cb;
void cut(int n, int x, int y) {
    bool isBlue = paper[x][y];
    if (n < 1) {
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (paper[x + i][y + j] != isBlue) {
                cut(n / 2, x, y);
                cut(n / 2, x + n / 2, y);
                cut(n / 2, x, y + n / 2);
                cut(n / 2, x + n / 2, y + n / 2);
                return;
            }
        }
    }
    isBlue ? cb++ : cw++;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    paper = new bool *[n];
    for (int i = 0; i < n; i++)
        paper[i] = new bool[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    cut(n, 0, 0);
    cout << cw << '\n'
         << cb;
    for (int i = 0; i < n; i++)
        delete[] paper[i];
    delete[] paper;
    return 0;
}