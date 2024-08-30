#include <cstdio>

int main() {
    int N, c = 0;
    scanf("%d", &N);
    for (int i = 1; i*i <= N; i++) c++;
    printf("%d", c);
}