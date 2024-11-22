// a * b / gcd = lcm
#include <stdio.h>

int get_gcd(int a, int b) {
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    int r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int gcd, lcm;
    scanf("%d%d", &gcd, &lcm);

    int min_a = 1e9, min_b = 1e9;

    for (int a = gcd; a <= lcm; a++) {
        if (((long long)lcm * gcd) % a != 0) continue;
        int b = (long long)lcm * gcd / a;

        if (get_gcd(a, b) == gcd) {
            if (a + b < min_a + min_b)
                min_a = a, min_b = b;
        }
    }

    printf("%d %d", min_a, min_b);

    return 0;
}