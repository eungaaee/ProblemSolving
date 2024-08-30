#include <cstdio>
#include <queue>
using namespace std;
int main() {
    int testcase, n, m, t, imptc[9], bp, c;
    queue<int> q;
    scanf("%d", &testcase);
    for (int i = 0; i < testcase; i++) {
        while (!q.empty()) {
            q.pop();
        }
        for (int j = 0; j <= 8; j++) {
            imptc[j] = 0;
        }
        bp = 8;
        c = 0;

        scanf("%d%d", &n, &m);
        for (int j = 0; j < n; j++) {
            scanf("%d", &t);
            q.push(t);
            imptc[t - 1]++;
        }
        while (!q.empty()) {
            while (imptc[bp] == 0) {
                bp--;
            }
            if (q.front() == bp + 1) {
                c++;
                if (m == 0) {
                    printf("%d ", c);
                    break;
                }
                q.pop();
                m--;
                imptc[bp]--;
            } else {
                t = q.front();
                q.pop();
                q.push(t);
                if (m == 0) {
                    m = q.size() - 1;
                } else {
                    m--;
                }
            }
        }
    }
    return 0;
}