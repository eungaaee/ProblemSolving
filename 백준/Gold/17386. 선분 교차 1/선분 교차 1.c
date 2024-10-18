// 선분의 양 끝 점을 기준으로 다른 선분의 양 끝 점을 한 점씩 외적해서 양쪽에 있는지 판단하기 (-1이면 왼쪽, 1이면 오른쪽)
#include <stdio.h>

typedef long long ll;

struct xy {
    int x, y;
};

int cross_product(struct xy *p1, struct xy *p2, struct xy *p3) {
    ll leftTie = (ll)p1->x * p2->y + (ll)p2->x * p3->y + (ll)p3->x * p1->y;
    ll rightTie = (ll)p1->y * p2->x + (ll)p2->y * p3->x + (ll)p3->y * p1->x;

    if (leftTie - rightTie > 0) return 1;
    else if (leftTie - rightTie < 0) return -1;
    else return 0;
}

int main() {
    struct xy L1[2], L2[2];

    for (int i = 0; i < 2; i++)
        scanf("%d%d", &L1[i].x, &L1[i].y);
    for (int i = 0; i < 2; i++)
        scanf("%d%d", &L2[i].x, &L2[i].y);

    // L1-p1, L1-p2 선분일 때, L2-p1 점의 외적값과 L2-p2의 외적값의 부호가 다르면 두 선분이 교차한다.
    int L1LineL2Dot = cross_product(L1, L1+1, L2) * cross_product(L1, L1+1, L2+1);
    int L2LineL1Dot = cross_product(L2, L2+1, L1) * cross_product(L2, L2+1, L1+1);

    printf("%d", L1LineL2Dot <= 0 && L2LineL1Dot <= 0); // L1이 기준일 때, L2가 기준일 때 둘 다 해봐야 한다. 한 개만 했을 때 반례가 발생하는 경우 있음

    return 0;
}