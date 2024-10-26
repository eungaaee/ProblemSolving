#include <iostream>
#include <queue>
using namespace std;

vector<int> order[32001];
int indegree[32001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        order[A].push_back(B);
        indegree[B]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; i++)
        if (indegree[i] == 0) pq.push(i);

    // 위상정렬, A_i -> B인 모든 A_i를 풀고나서 B를 풀기
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        for (int next : order[cur]) {
            indegree[next]--;
            if (indegree[next] == 0) pq.push(next);
        }

        cout << cur << ' ';
    }

    return 0;
}