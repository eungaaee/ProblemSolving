// 가장 용량이 적은 가방부터 최대한 비싼 보석을 넣기
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    struct crystal {
        int M, V;
        
        bool operator<(const struct crystal &c) const {
            return M < c.M;
        }
    };

    struct crystal *crystals = new struct crystal[N];
    for (int i = 0; i < N; i++) {
        cin >> crystals[i].M >> crystals[i].V;
    }

    int *bags = new int[K];
    for (int i = 0; i < K; i++) {
        cin >> bags[i];
    }

    sort(crystals, crystals+N);
    sort(bags, bags+K);

    priority_queue<int> pq;
    long long ans = 0;

    for (int i = 0, j = 0; i < K; i++) {
        while (j < N && crystals[j].M <= bags[i]) {
            pq.push(crystals[j].V);
            j++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}