#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int stack[N], top = -1;
    long long ans = 0;
    int h;

    for (int i = 0; i < N; i++) {
        scanf("%d", &h);
        if (top < 0) stack[++top] = h;
        else {
            while (top >= 0 && h >= stack[top]) top--;
            ans += top+1; // top+1 == size of stack
            stack[++top] = h;
        }
    }

    printf("%lld", ans);

    return 0;
}