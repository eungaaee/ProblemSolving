#include <malloc.h>
#include <stdio.h>
int sp = -1, *s;
void push(int t) {
    s[++sp] = t;
}
int pop() {
    return s[sp--];
}
int main() {
    int n, t, *arr, rp = 0;
    char *result;
    scanf("%d", &n);
    s = (int *)malloc(4 * n);
    arr = (int *)malloc(4 * n);
    result = (char *)malloc(n * 2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        arr[i] = t;
    }
    int i, j;
    for (i = 0, j = 0; i < n && j <= n;) {
        if (arr[i] == s[sp]) {
            pop();
            i++;
            result[rp] = '-';
        } else {
            j++;
            push(j);
            result[rp] = '+';
        }
        rp++;
    }
    if (i < n) {  // i: 0~7 돌고 마지막 i++때문에 8이어야 정상.
        puts("NO");
    } else {
        for (int i = 0; i < rp; i++) {
            printf("%c\n", result[i]);
        }
    }
    return 0;
}