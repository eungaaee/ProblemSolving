#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, string>> q;
int b;
bool visit[10000];
void bfs() {
    int num, newNum;
    string op;
    while (!q.empty()) {
        num = q.front().first;
        op = q.front().second;
        q.pop();
        // D
        newNum = num * 2 % 10000;
        if (newNum == b) {
            cout << op + 'D' << '\n';
            return;
        }
        if (!visit[newNum]) {
            visit[newNum] = 1;
            q.push({newNum, op + 'D'});
        }
        // S
        newNum = num == 0 ? 9999 : num - 1;
        if (newNum == b) {
            cout << op + 'S' << '\n';
            return;
        }
        if (!visit[newNum]) {
            visit[newNum] = 1;
            q.push({newNum, op + 'S'});
        }
        // L
        newNum = num % 1000 * 10 + num / 1000;
        if (newNum == b) {
            cout << op + 'L' << '\n';
            return;
        }
        if (!visit[newNum]) {
            visit[newNum] = 1;
            q.push({newNum, op + 'L'});
        }
        // R
        newNum = num / 10 + num % 10 * 1000;
        if (newNum == b) {
            cout << op + 'R' << '\n';
            return;
        }
        if (!visit[newNum]) {
            visit[newNum] = 1;
            q.push({newNum, op + 'R'});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, a;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        visit[a] = 1;
        q.push({a, ""});
        bfs();
        while (!q.empty())
            q.pop();
        for (int i = 0; i < 10000; i++)
            visit[i] = 0;
    }
}