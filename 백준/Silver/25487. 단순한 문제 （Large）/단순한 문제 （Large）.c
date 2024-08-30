#include <stdio.h>
int main() {
    int t, a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", a<b?a<c?a:c:b<c?b:c);
    }
    return 0;
}