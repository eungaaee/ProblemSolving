#include <iostream>
#include <map>
#include <queue>
using namespace std;
int main() {
    priority_queue<int, vector<int>, less<int>> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    map<int, int> c;
    int T, k, n;
    char o;
    cin >> T;
    while (T--) {
        while (!maxPQ.empty()) maxPQ.pop();
        while (!minPQ.empty()) minPQ.pop();
        c.clear();
        cin >> k;
        while (k--) {
            cin >> o >> n;
            if (o == 'I') {
                maxPQ.push(n);
                minPQ.push(n);
                c[n]++;
            } else {
                if (n == 1 && !maxPQ.empty()) {
                    c[maxPQ.top()]--;
                    maxPQ.pop();
                } else if (n == -1 && !minPQ.empty()) {
                    c[minPQ.top()]--;
                    minPQ.pop();
                }
                while (!maxPQ.empty() && c[maxPQ.top()] == 0) maxPQ.pop();
                while (!minPQ.empty() && c[minPQ.top()] == 0) minPQ.pop();
            }
        }
        if (maxPQ.empty() || minPQ.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << maxPQ.top() << ' ' << minPQ.top() << '\n';
        }
    }
    return 0;
}