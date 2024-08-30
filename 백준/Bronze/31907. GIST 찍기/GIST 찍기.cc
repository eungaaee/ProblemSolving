#include <cstdio>

int main() {
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) putchar('G');
        for (int j = 0; j < K * 3; j++) putchar('.');
        putchar('\n');
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) putchar('.');
        for (int j = 0; j < K; j++) putchar('I');
        for (int j = 0; j < K; j++) putchar('.');
        for (int j = 0; j < K; j++) putchar('T');
        putchar('\n');
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K*2; j++) putchar('.');
        for (int j = 0; j < K; j++) putchar('S');
        for (int j = 0; j < K; j++) putchar('.');
        putchar('\n');
    }
    return 0;
}