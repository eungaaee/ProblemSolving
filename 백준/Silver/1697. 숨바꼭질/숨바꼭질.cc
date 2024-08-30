#include <iostream>
#include <queue>
using namespace std;
int n, k;
bool visit[100001];
void bfs() {
    int x, c;
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    while (!q.empty()) {
        x = q.front().first;
        c = q.front().second;
        if (x == k) {
            cout << c;
            break;
        }
        if (x + 1 >= 0 && x + 1 <= 100000 && !visit[x + 1]) {
            q.push(make_pair(x + 1, c + 1));
            visit[x + 1] = 1;
        }
        if (x - 1 >= 0 && x - 1 <= 100000 && !visit[x - 1]) {
            q.push(make_pair(x - 1, c + 1));
            visit[x - 1] = 1;
        }
        if (x * 2 >= 0 && x * 2 <= 100000 && !visit[x * 2]) {
            q.push(make_pair(x * 2, c + 1));
            visit[x * 2] = 1;
        }
        q.pop();
    }
}
int main() {
    cin >> n >> k;
    visit[n] = 1;
    bfs();
    return 0;
}