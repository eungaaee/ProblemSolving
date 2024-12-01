// 시작시간 빠른 순서로 pq의 top에 있는 도착시간과 비교해서 더 나중이면 pop, 더 먼저면 새 도착시간을 push
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> lecture;

    for (int i = 0, S, T; i < N; i++) {
        cin >> S >> T;
        lecture.push_back({S, T});
    }

    sort(lecture.begin(), lecture.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        if (!pq.empty() && lecture[i].first >= pq.top()) {
            pq.pop();
            pq.push(lecture[i].second);
        } else {
            pq.push(lecture[i].second);
        }
    }

    cout << pq.size();

    return 0;
}