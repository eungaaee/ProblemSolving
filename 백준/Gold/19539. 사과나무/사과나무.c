#include <stdio.h>

int main() {
    int N, h, sum = 0, twosDay = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &h);
        sum += h;
        twosDay += h / 2;
    }
    if (sum % 3) printf("NO");
    else if (twosDay < sum / 3) printf("NO");
    else printf("YES");
    return 0;
}