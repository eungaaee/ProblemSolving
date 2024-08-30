#include <bits/stdc++.h>
using namespace std;

bool np[246913];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i*i <= 246912; ++i) {
        if (np[i]==1) continue;
        for (int j = i*i; j <= 246912; j+=i) {
            np[j] = 1;
        }
    }

    int n, c;
    while (1) {
        cin >> n;
        if (!n) break;
        c = 0;
        for (int i = n+1; i <= n*2; ++i) {
            if (np[i]) continue;
            c++;
        }
        cout << c << '\n';
    }
    return 0;
}