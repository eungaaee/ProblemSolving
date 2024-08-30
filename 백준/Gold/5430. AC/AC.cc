#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, lptr, rptr;
    vector<int> arr;
    bool isReverse;
    string p, rawArr;
    cin >> t;
    while (t--) {
        arr.clear();
        arr.push_back(0);
        lptr = 0;
        rptr = 0;
        isReverse = 0;
        cin >> p >> n >> rawArr;
        for (int i = 1; i < rawArr.length() - 1; i++) {
            if (rawArr[i] == ',') {
                rptr++;
                arr.push_back(0);
                continue;
            }
            arr[rptr] = arr[rptr] * 10 + rawArr[i] - 48;
        }
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R')
                isReverse = !isReverse;
            else {
                n--;
                if (isReverse) {
                    rptr--;
                } else {
                    lptr++;
                }
            }
        }
        if (n == 0) {
            cout << "[]";
        } else if (lptr > rptr) {
            cout << "error";
        } else {
            cout << '[';
            if (isReverse) {
                for (int i = rptr; i > lptr; i--) {
                    cout << arr[i] << ',';
                }
                cout << arr[lptr];
            } else {
                for (int i = lptr; i < rptr; i++) {
                    cout << arr[i] << ',';
                }
                cout << arr[rptr];
            }
            cout << ']';
        }
        cout << '\n';
    }
}