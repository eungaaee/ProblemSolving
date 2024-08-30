#include <stdio.h>
int main() {
    int n, x1, y1, r1, x2, y2, r2, distance, largeR;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
        distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        largeR = r1 * r1 > r2 * r2 ? r1 * r1 : r2 * r2;
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) {
                puts("-1");
            } else {
                puts("0");
            }                                                           // 원1>원2 일 떄,
        } else if (largeR > distance) {  // 원1 안에 원2의 중심이 있는 경우
            if ((r1 - r2) * (r1 - r2) < distance) {
                puts("2");
            } else if ((r1 - r2) * (r1 - r2) == distance) {
                puts("1");
            } else if ((r1 - r2) * (r1 - r2) > distance) {
                puts("0");
            }
        } else if (largeR == distance) {  // 원2의 중심이 원1의 둘레에 있는 경우
            puts("2");
        } else if (largeR < distance) {  // 원1 밖에 원2의 중심이 있는 경우
            if ((r1 + r2) * (r1 + r2) > distance) {
                puts("2");
            } else if ((r1 + r2) * (r1 + r2) == distance) {
                puts("1");
            } else if ((r1 + r2) * (r1 + r2) < distance) {
                puts("0");
            }
        }
    }
}