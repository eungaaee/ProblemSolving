#include <stdio.h>

typedef struct {
    int sour;
    int bitter;
} taste;

int N, min = 0x7fffffff;
taste *ingred;

int abs(int n) { return n < 0 ? -n : n; }

void backtrack(int idx, int cnt, int sour, int bitter) {
    if (cnt > 0 && abs(sour-bitter) < min) min = abs(sour-bitter);

    for (int i = idx; i < N; i++)
        backtrack(i+1, cnt+1, sour*ingred[i].sour, bitter+ingred[i].bitter);
}

int main() {
    scanf("%d", &N);

    ingred = (taste *)malloc(N * sizeof(taste));
    for (int i = 0; i < N; i++)
        scanf("%d%d", &ingred[i].sour, &ingred[i].bitter);

    backtrack(0, 0, 1, 0);
    printf("%d", min);

    free(ingred);
    return 0;
}