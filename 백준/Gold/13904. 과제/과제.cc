#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { // 점수 내림차순 정렬
    if (a.second == b.second) return a.first > b.first;
    else return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    pair<int, int> assignment[N];
    for (int i = 0; i < N; i++) {
        cin >> assignment[i].first >> assignment[i].second;
    }
    sort(assignment, assignment+N, compare);

    bool calendar[1001] = {};
    int score = 0;
    for (int i = 0; i < N; i++) {
        auto [d, w] = assignment[i];

        while (d >= 1 && calendar[d]) d--;
        if (d < 1) continue;
        calendar[d] = true;
        score += w;
    }

    cout << score;

    return 0;
}