#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;

        while (!pq.empty() && pq.top().second < i-L+1) pq.pop();
        pq.push({A, i});

        cout << pq.top().first << ' ';
    }

    return 0;
}