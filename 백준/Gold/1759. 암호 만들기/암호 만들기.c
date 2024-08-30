#include <stdio.h>

int L, C;
char a[16], pw[16];

static inline void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

_Bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    else return 0;
}

void dfs(int size, int order, int v, int c) {
    if (size == L) {
        if (v >= 1 && c >= 2) printf("%s\n", pw);
        return;
    }

    while (order < C) {
        pw[size] = a[order];
        if (isVowel(a[order++])) dfs(size+1, order, v+1, c);
        else dfs(size+1, order, v, c+1);
    }
}

int main() {
    scanf("%d%d", &L, &C);
    for (int i = 0; i < C; i++) scanf(" %c", a+i);

    for (int i = 1; i < C; i++)
        for (int j = i; j > 0 && a[j-1] > a[j]; j--)
            swap(a+j-1, a+j);

    dfs(0, 0, 0, 0);

    return 0;
}