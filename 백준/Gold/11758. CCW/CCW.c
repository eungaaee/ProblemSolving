#include <stdio.h>

int main() {
    int P[3][2], leftTie = 0, rightTie = 0;
    for (int i = 0; i < 3; i++) scanf("%d%d", &P[i][0], &P[i][1]); // scanf("%d%d", *(P+i)+0, *(P+i)+1);
    for (int i = 0; i < 3; i++) {
        leftTie += P[i][0] * P[(i+1)%3][1];
        rightTie += P[i][1] * P[(i+1)%3][0];
    }
    if (leftTie - rightTie > 0) printf("1");
    else if (leftTie - rightTie < 0) printf("-1");
    else printf("0");
    return 0;
}