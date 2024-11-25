#include <stdio.h>

struct {
    char s[500000];
    int top;
} stack;

void reversed_print(int idx) {
    if (idx == 0) {
        putchar(stack.s[idx]);
        return;
    }
    reversed_print(idx-1);
    putchar(stack.s[idx]);
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);

    char num[N];
    scanf("%s", num);


    for (int i = 0; i < N; i++) {
        while (K > 0 && stack.top > 0 && num[i] > stack.s[stack.top-1]) {
            stack.top--;
            K--;
        }
        stack.s[stack.top++] = num[i];
    }

    reversed_print(stack.top-1 - K);

    return 0;
}