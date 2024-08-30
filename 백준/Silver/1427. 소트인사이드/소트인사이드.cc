#include <cstdio>

int main() {
    char N[11];
    int count[9]{};
    scanf("%s", &N);
    for (int i = 0; N[i]!='\0'; i++)
        count[N[i]-48]++;
    for (int i = 9; i >= 0;) {
        if (count[i] > 0) {
            printf("%d", i);
            count[i]--;
        } else {
            i--;
        }
    }
    return 0;
}