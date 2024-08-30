#include <cstdio>

int main() {
    int A, P, C;
    scanf("%d%d%d", &A, &P, &C);

    if (A+C > P) printf("%d", A+C);
    else printf("%d", P);
    return 0;
}