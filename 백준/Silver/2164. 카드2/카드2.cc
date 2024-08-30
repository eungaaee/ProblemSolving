#include <cstdio>
#include <queue>
int main() {
    std::queue<int> q;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    printf("%d", q.front());
    return 0;
}