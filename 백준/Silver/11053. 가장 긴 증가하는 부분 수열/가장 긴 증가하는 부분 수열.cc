#include <cstdio>
using namespace std;
int main() {
    int n, cur, c[1001]{}, prev{}, max{};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        prev = 0;
        scanf("%d", &cur);
        for (int i = cur - 1; i >= 0; i--) {
            if (c[i] > c[prev]) {
                prev = i;
            }
        }
        c[cur] = c[prev] + 1;
    }
    for (int i = 1; i < 1001; i++) {
        if (c[i] > max)
            max = c[i];
    }
    printf("%d", max);
}