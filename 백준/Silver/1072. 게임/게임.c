#include <stdio.h>

int main() {
    int X, Y;
    scanf("%d%d", &X, &Y);

    int Z = (long long)Y*100 / X;

    if (Z >= 99) printf("-1");
    else {
        int l = 0, r = 1e9, m;

        while (l <= r) {
            m = l+r>>1;

            int newZ = ((long long)Y+m)*100 / ((long long)X+m);
            if (newZ <= Z) l = m+1;
            else if (newZ > Z) r = m-1;
        }

        printf("%d", l);
    }

    return 0;
}