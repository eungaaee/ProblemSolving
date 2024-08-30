#include <iostream>
using namespace std;

bool isNotPrime[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i*i <= 1000000; i++) {
        if (isNotPrime[i]) continue;
        for (int j = i*i; j <= 1000000; j+=i) {
            isNotPrime[j] = 1;
        }
    }
    isNotPrime[1] = 1;

    int T;
    cin >> T;

    int n, x, y, c;
    while (T--) {
        c = 0;
        cin >> n;
        x = y = n/2;
        for (int i = 0; i < n/2; i++) {
            if (!isNotPrime[x] & !isNotPrime[y]) c++;
            x--, y++;
        }
        cout << c << '\n';
    }
    return 0;
}