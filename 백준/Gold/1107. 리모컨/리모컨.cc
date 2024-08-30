#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, t, c{0x3f3f3f};
    bool isBroken[10]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, isAvailable;
    string strI;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        isBroken[t] = 1;
    }
    for (int i = 0; i <= 999999; i++) {
        isAvailable = 1;
        strI = to_string(i);
        for (int j = 0; j < strI.length(); j++) {
            if (isBroken[strI[j] - 48]) {
                isAvailable = 0;
                break;
            }
        }
        if (isAvailable) {
            c = (strI.length() + (n > i ? n - i : i - n)) < c ? (strI.length() + (n > i ? n - i : i - n)) : c;
        }
    }
    if (n - 100 >= 0 && n - 100 < c)
        cout << n - 100;
    else if (100 - n >= 0 && 100 - n < c)
        cout << 100 - n;
    else
        cout << c;
    return 0;
}