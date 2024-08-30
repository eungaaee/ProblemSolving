#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cost[100000], sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> cost[i], sum += cost[i];

    sort(cost, cost+N);
    for (int i = N-3; i >= 0; i -= 3) sum -= cost[i];
    cout << sum;
    return 0;
}