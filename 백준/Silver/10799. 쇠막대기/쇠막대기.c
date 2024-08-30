#include <stdio.h>

int main() {
    char prev = getchar(), cur;
    int stick = 0, ans = 0;
    while ((cur = getchar()) != EOF) {
        if (prev == '(' && cur == ')') ans += stick; // 레이저
        else if (prev == '(') stick++; // 막대기 시작
        else if (cur == ')') ans++, stick--; // 막대기 끝
        prev = cur;
    }
    printf("%d", ans);
    return 0;
}