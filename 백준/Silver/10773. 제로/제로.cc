#include <cstdio>
#include <stack>
int main() {
    int k, t, summary = 0;
    std::stack<int> s;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &t);
        t ? s.push(t) : s.pop();
    }
    while (!s.empty()) {
        summary += s.top();
        s.pop();
    }
    printf("%d", summary);
    return 0;
}