/*
1: 1
2: 1+1, 2
3: 1+1+1, 1+2, 2+1, 3
4: 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 1+3, 3+1, 2+2

method[i] = method[i-1] (1을 더하는 경우) + method[i-2] (2를 더하는 경우) + method[i-3] (3을 더하는 경우)
*/

#include <stdio.h>

int main() {
    int method[11] = {[1] = 1, [2] = 2, [3] = 4};
    for (int i = 4; i <= 10; i++)
        method[i] = method[i-1] + method[i-2] + method[i-3];

    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", method[n]);
    }

    return 0;
}