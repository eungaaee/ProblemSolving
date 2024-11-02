#include <stdio.h>

int main() {
    char stack[30], p = 0; // 올바르지 못한 괄호열 판별 용도
    char c, prev_c;
    int ans = 0, localAns = 1;

    while ((c = getchar()) != EOF) {
        if (c == '(') {
            stack[p++] = '(';
            localAns *= 2;
        } else if (c == '[') {
            stack[p++] = '[';
            localAns *= 3;
        } else if (c == ')') {
            if (p == 0 || stack[p-1] == '[') {
                ans = 0;
                break;
            }

            if (prev_c == '(') ans += localAns;

            p--;
            localAns /= 2;
        } else if (c == ']') {
            if (p == 0 || stack[p-1] == '(') {
                ans = 0;
                break;
            }

            if (prev_c == '[') ans += localAns;

            p--;
            localAns /= 3;
        }

        prev_c = c;
    }

    if (p > 0) ans = 0;
    printf("%d", ans);

    return 0;
}