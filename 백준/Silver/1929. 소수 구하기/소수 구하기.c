#include <malloc.h>
#include <stdio.h>
int main() {
    int m, n, *arr;
    scanf("%d%d", &m, &n);
    if (m == 1) {
        m = 2;
        if (n == 1) {
            return 0;
        }
    }
    arr = (int*)malloc(sizeof(int)* (n+1));
    for (int i = 2; i <= n; i++) {
        arr[i] = i;
    }
    for (int i = 2; i * i <= n; i++) {
        if (arr[i] == 0) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            arr[j] = 0;
        }
    }
    for (int i = m; i <= n; i++) {
        if (arr[i]) {
            printf("%d\n", arr[i]);
        }
    }
    free(arr);
    return 0;
}