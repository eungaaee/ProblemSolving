#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, coin[101], count[10001];
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> coin[i];
    count[0] = 0;
    for (int i = 1; i <= k; i++) count[i] = 10001;

    for (int i = 1; i <= n; i++) {
        for (int j = coin[i]; j <= k; j++)
            if (count[j] > count[j-coin[i]]+1) count[j] = count[j-coin[i]]+1;
    }
    if (count[k] <= 10000) cout << count[k];
    else cout << -1;
    return 0;
}