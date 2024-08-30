// 3의 배수는 각 자리수들을 더한 값이 3으로 나누어 떨어진다.
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    if (*(char*)a < *(char*)b) return 1;
    else if (*(char*)a > *(char*)b) return -1;
    else return 0;
}

int main() {
    char N[100001];
    scanf("%s", N);

    int len;
    _Bool noZero = 1;
    for (len = 0; N[len] != '\0'; len++)
        if (N[len] == '0') noZero = 0; 

    if (noZero) printf("-1");
    else {
        int sum = 0;
        for (int i = 0; i < len; i++) sum += N[i]-'0';

        if (sum % 3) printf("-1");
        else {
            qsort(N, len, 1, compare);
            printf("%s", N);
        }
    }
    
    return 0;
}