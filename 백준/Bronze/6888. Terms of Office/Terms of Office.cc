#include <cstdio>

int main() {
    int X, Y;
    scanf("%d%d", &X, &Y);
    for (int i = X; i <= Y; i += 60)
        printf("All positions change in year %d\n", i);
    return 0;
}