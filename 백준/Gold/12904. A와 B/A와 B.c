#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int length = strlen(str);

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length-1 - i];
        str[length-1 - i] = temp;
    }
}

int main() {
    char S[1000], T[1001];
    scanf("%s%s", S, T);

    while (1) {
        if (strlen(S) == strlen(T)) {
            printf("%d", strcmp(S, T) == 0);
            break;
        }

        int end = strlen(T) - 1;
        if (T[end] == 'A') T[end] = '\0';
        else if (T[end] == 'B') {
            T[end] = '\0';
            reverse(T);
        }
    }

    return 0;
}