#include <iostream>
using namespace std;
int n, m;
void narr(int num, int c) {
    static int arr[8];
    arr[c - 1] = num;
    if (c == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++)
        narr(i, c + 1);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        narr(i, 1);
    return 0;
}