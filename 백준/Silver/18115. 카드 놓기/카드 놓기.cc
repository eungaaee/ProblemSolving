#include <iostream>
using namespace std;
int iniCards[1000000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, card, top{}, bottom, t, skip_top{};
    cin >> n;
    card = n;
    bottom = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 1) {
            iniCards[top] = card;
            card--;
            top += 1 + skip_top;
            skip_top = 0;
        } else if (t == 2) {
            skip_top++;
            iniCards[top + skip_top] = card;
            card--;
        } else {
            iniCards[bottom] = card;
            card--;
            bottom--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << iniCards[i] << ' ';
    return 0;
}