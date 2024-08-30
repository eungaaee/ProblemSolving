#include <stdio.h>

int main() {
    char polynomial[14];
    int n1 = -100000, n2 = 0, sign = 1;
    scanf("%s", polynomial);
    for (int i = 0; polynomial[i] != '\0'; i++) {
        if (polynomial[i] == 'x') {
            n1 = sign*n2;
            sign = 1, n2 = 0;
        } else if (polynomial[i] == '+') continue;
        else if (polynomial[i] == '-') sign = -1;
        else {
            n2 = n2*10 + polynomial[i]-'0';
        }
    }
    n2 *= sign;

    if (n1 == -100000) { // 0차
        if (n2 == 0) putchar('W');
        else if (n2 == 1) printf("x+W");
        else if (n2 == -1) printf("-x+W");
        else printf("%dx+W", n2);
    } else { // 1차
        n1 /= 2; // 적분

        if (n1 == 1) printf("xx");
        else if (n1 == -1) printf("-xx");
        else printf("%dxx", n1);

        if (n2 == 1) printf("+x");
        else if (n2 == -1) printf("-x"); 
        else if (n2 > 0) printf("+%dx", n2);
        else if (n2 < 0) printf("%dx", n2);
        printf("+W");
    }
    return 0;
}