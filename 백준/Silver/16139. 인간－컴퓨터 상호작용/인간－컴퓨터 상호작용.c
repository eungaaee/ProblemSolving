#include <stdio.h>

int freq[26][200001];

int main() {
    char S[200001], a;
    int q, l, r;
    scanf("%s%d", S, &q);
    for (int i = 1; S[i-1] != '\0'; i++) {
        for (int j = 0; j < 26; j++)
            freq[j][i] = freq[j][i-1] + (S[i-1]-'a' == j);
    }
    while (q--) {
        scanf(" %c%d%d", &a, &l, &r);
        printf("%d\n", freq[a-'a'][r+1] - freq[a-'a'][l]);
    }
    return 0;
}