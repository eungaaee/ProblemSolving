#include <stdio.h>

int toInteger(char n[]) {
    int ret = 0;
    for (int i = 0; n[i] != '\0'; i++)
        ret = ret*10 + n[i]-'0';
    return ret;
}

int main() {
    char a[9], b[9], c[9];
    scanf("%s%s%s", a, b, c);

    int num, order;
    if ('0' <= a[0] && a[0] <= '9') num = toInteger(a), order = 0;
    else if ('0' <= b[0] && b[0] <= '9') num = toInteger(b), order = 1;
    else num = toInteger(c), order = 2;

    num += 3-order;
    if (num % 15 == 0) printf("FizzBuzz");
    else if (num % 3 == 0) printf("Fizz");
    else if (num % 5 == 0) printf("Buzz");
    else printf("%d", num);
    return 0;
}