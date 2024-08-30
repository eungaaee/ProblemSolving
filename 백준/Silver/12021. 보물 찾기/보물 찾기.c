#include <stdio.h>

int main() {
    float a, b, x, y;
    scanf("%f%f", &a, &b);
    while (1) {
        x = (a+b)/2, y = a*b/(a+b)*2;
        if (a == x && b == y) break;
        a = x, b = y;
    }
    printf("%.3f %.3f", x, y);
    return 0;
}