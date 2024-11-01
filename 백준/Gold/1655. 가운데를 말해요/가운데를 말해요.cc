#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int> pq_l;
    priority_queue<int, vector<int>, greater<int>> pq_r;
    int cur;
    
    for (int i = 0; i < N; i++) {
        cin >> cur;

        if (pq_l.size() > pq_r.size()) pq_r.push(cur);
        else pq_l.push(cur);

        if (!pq_l.empty() && !pq_r.empty() && pq_l.top() > pq_r.top()) {
            int t = pq_l.top();
            pq_l.pop();
            pq_l.push(pq_r.top());
            pq_r.pop();
            pq_r.push(t);
        }

        cout << pq_l.top() << '\n';
    }
    
    return 0;
}