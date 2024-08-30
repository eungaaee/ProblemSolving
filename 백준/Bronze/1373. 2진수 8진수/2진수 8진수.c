#include <stdio.h>

int main() {
    char bin[1000001];
    scanf("%s", bin);
    int l;
    for (l = 0; bin[l] != '\0'; l++);

    int oct;
    if (l%3 == 1) {
        oct = (bin[0]-'0')*1;
        printf("%d", oct);
    } else if (l%3 == 2) {
        oct = (bin[0]-'0')*2 + (bin[1]-'0')*1;
        printf("%d", oct);
    }

    for (int i = l%3; i < l; i += 3) {
        oct = (bin[i]-'0')*4 + (bin[i+1]-'0')*2 + (bin[i+2]-'0')*1;
        printf("%d", oct);
    }

    return 0;
}