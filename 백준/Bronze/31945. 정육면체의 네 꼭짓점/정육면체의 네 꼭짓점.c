#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int p[4];
    while (T--) {
        scanf("%d%d%d%d", p, p+1, p+2, p+3);
        for (int i = 0; i < 3; i++)
            for (int j = 3; j > i; j--)
                if (p[j-1] > p[j]) p[j]^=p[j-1], p[j-1]^=p[j], p[j]^=p[j-1];

        if ((p[0]==0 && p[1]==2 && p[2]==4 && p[3]==6)
        || (p[0]==0 && p[1]==1 && p[2]==2 && p[3]==3)
        || (p[0]==0 && p[1]==1 && p[2]==4 && p[3]==5)
        || (p[0]==1 && p[1]==3 && p[2]==5 && p[3]==7)
        || (p[0]==4 && p[1]==5 && p[2]==6 && p[3]==7)
        || (p[0]==2 && p[1]==3 && p[2]==6 && p[3]==7)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}