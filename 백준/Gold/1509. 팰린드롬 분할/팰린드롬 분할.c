/*
1. isPalindrome[][] 판별하기
2. minPartition[] 채우기 (동적계획)
*/
#include <stdio.h>
#define INF 0x3f3f3f3f

int main() {
    char s[2502];
    scanf("%s", s+1);

    int strLen;
    for (strLen = 1; s[strLen+1] != '\0'; strLen++);

    // 1.
    _Bool isPalindrome[strLen+1][strLen+1];
    for (int i = 1; i <= strLen; i++)
        for (int j = 1; j <= strLen; j++)
            isPalindrome[i][j] = 0;

    // i to i
    for (int i = 1; i <= strLen; i++) isPalindrome[i][i] = 1;

    // i-1 to i
    for (int i = 2; i <= strLen; i++)
        if (s[i-1] == s[i]) isPalindrome[i-1][i] = 1;

    // i to j
    /* for (int L = strLen-2; L >= 1; L--) {
        for (int R = L+2; R <= strLen; R++) {
            if (isPalindrome[L+1][R-1] && s[L] == s[R]) isPalindrome[L][R] = 1;
        }
    } */
    for (int R = 3; R <= strLen; R++) {
        for (int L = 1; L <= R-2; L++) {
            if (isPalindrome[L+1][R-1] && s[L] == s[R]) isPalindrome[L][R] = 1;
        }
    }

    // 2.
    int minPartition[strLen+1];
    minPartition[0] = 0;

    for (int R = 1; R <= strLen; R++) {
        minPartition[R] = INF;
        for (int L = 1; L <= R; L++) {
            if (isPalindrome[L][R] && minPartition[L-1] + 1 < minPartition[R])
                minPartition[R] = minPartition[L-1] + 1;
        }
    }

    // printf("%d", isPalindrome[1][11]);
    printf("%d", minPartition[strLen]);

    return 0;
}