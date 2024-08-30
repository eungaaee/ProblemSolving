#include <iostream>
using namespace std;
int num[500000], loc[500000], count[500000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        num[t - 1] = i;
        loc[i] = t - 1;
    }
    for (int i = 0; i < n; i++) {
        if (num[i] != i) {
            t = num[i];
            num[i] = i;
            num[loc[i]] = t;
            count[i] += t-i;
            count[loc[i]] += t-i;
            loc[t] = loc[i];
            loc[i] = i;
        }
    }
    for (int i = 0; i < n; i++)
        cout << count[i] << ' ';
}