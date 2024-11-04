#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b); // '\0' 과 비교하게되므로 길이가 더 짧은 게 앞으로 옴
}

_Bool isSubstring(char *a, char *b) {
    for (int i = 0; i < strlen(a); i++)
        if (a[i] != b[i]) return 0;
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char number[n][11];
        for (int i = 0; i < n; i++) scanf("%s", number[i]);
        qsort(number, n, 11, compare);

        _Bool isConsistent = 1;
        for (int i = 1; i < n; i++) {
            if (strlen(number[i-1]) > strlen(number[i])) continue; // prev의 길이가 cur보다 길면 겹칠 일이 없다.
            else if (isSubstring(number[i-1], number[i])) {
                isConsistent = 0;
                break;
            }
        }

        printf(isConsistent ? "YES\n" : "NO\n");
    }

    return 0;
}