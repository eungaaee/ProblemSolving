#include <iostream>
#include <string>
using namespace std;
int n, m, c{};
void dfs(char **arr, int x, int y) {
    static const int ndxdy[4] = {0, 0, -1, 1};
    switch (arr[x][y]) {
        case 'P':
            c++;
        case 'I':
        case 'O':
            arr[x][y] = 'X';
            break;
        case 'X':
            return;
    }
    for (int i = 0; i < 4; i++) {
        if (x + ndxdy[i] >= 0 && y + ndxdy[3 - i] >= 0 && x + ndxdy[i] < n && y + ndxdy[3 - i] < m) {
            dfs(arr, x + ndxdy[i], y + ndxdy[3 - i]);
        }
    }
}
int main() {
    int x, y;
    char **campus;
    string info;
    cin >> n >> m;
    campus = new char *[n];
    for (int i = 0; i < n; i++) {
        campus[i] = new char[m];
    }
    for (int i = 0; i < n; i++) {
        cin >> info;
        for (int j = 0; j < m; j++) {
            if (info[j] == 'I') {
                x = i;
                y = j;
            }
            campus[i][j] = info[j];
        }
    }
    dfs(campus, x, y);
    if (c == 0)
        cout << "TT";
    else
        cout << c;
    for (int i = 0; i < n; i++) {
        delete[] campus[i];
    }
    delete[] campus;
    return 0;
}