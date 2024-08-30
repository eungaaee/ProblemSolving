#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, arr[200000], op1, op2, op3, shift{};
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (q--) {
        cin >> op1 >> op2;
        if (op1 == 1) {
            cin >> op3;
            arr[(n-shift + op2-1) % n] += op3;
        } else if (op1 == 2) {
            shift += op2;
            if (shift > n-1)
                shift -= n;
        } else {
            shift -= op2;
            if (shift < 0)
                shift += n;
        }
    }
    for (int i = n-shift; i < n; i++)
        cout << arr[i] << ' ';
    for (int i = 0; i < n-shift; i++)
        cout << arr[i] << ' ';
}