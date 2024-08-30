#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    vector<pair<int, int>> a;
    cin >> T;
    while (T--) {
        a.clear();
        cin >> N;
        int g1, g2;
        for (int i = 0; i < N; i++) {
            cin >> g1 >> g2;
            a.push_back({g1, g2});
        }
        sort(a.begin(), a.end());

        int prevG2 = 100001, c = 0;
        for (int i = 0; i < N; i++) {
            if (prevG2 > a[i].second) {
                prevG2 = a[i].second;
                c++;
            }
        }
        cout << c << '\n';
    }
    return 0;
}