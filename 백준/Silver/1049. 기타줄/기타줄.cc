#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    int minPkg = INF, minOne = INF, pkg, one;
    for (int i = 0; i < M; ++i) {
        cin >> pkg >> one;
        if (minPkg > pkg) minPkg = pkg;
        if (minOne > one) minOne = one;
    }
    int ans1, ans2, ans3;
    ans1 = (N/6 + (N%6>0)) * minPkg;
    ans2 = N * minOne;
    ans3 = N/6 * minPkg + N%6 * minOne;
    cout << min({ans1, ans2, ans3});
    return 0;
}