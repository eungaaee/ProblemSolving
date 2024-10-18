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

// a <= b
_Bool compare(struct xy *a, struct xy *b) {
    if (a->x == b->x) {
        if (a->y <= b->y) return 1;
        else return 0;
    } else return a->x <= b->x;
}

int main() {
    struct xy L1[2], L2[2];

    for (int i = 0; i < 2; i++)
        scanf("%d%d", &L1[i].x, &L1[i].y);
    for (int i = 0; i < 2; i++)
        scanf("%d%d", &L2[i].x, &L2[i].y);

    int L1LineL2Point = cross_product(L1, L1+1, L2) * cross_product(L1, L1+1, L2+1);   // L1이 선분일 때, L2의 각 끝점과의 외적의 곱
    int L2LineL1Point = cross_product(L2, L2+1, L1) * cross_product(L2, L2+1, L1+1);   // L2가 선분일 때, L1의 각 끝점과의 외적의 곱

    _Bool isIntersect;
    if (L1LineL2Point == 0 && L2LineL1Point == 0) { // 포개어져 있거나(교차 O), 그렇지 않고 일직선상에 두 선분이 존재하거나(교차 X)
        struct xy L1_Small, L1_Big, L2_Small, L2_Big; // 각 선분에서 무엇이 더 오른쪽 위에 있는지 분류

        if (compare(L1, L1+1)) L1_Small = L1[0], L1_Big = L1[1];
        else L1_Small = L1[1], L1_Big = L1[0];
        if (compare(L2, L2+1)) L2_Small = L2[0], L2_Big = L2[1];
        else L2_Small = L2[1], L2_Big = L2[0];

        if ((compare(&L1_Small, &L2_Big) && compare(&L2_Small, &L1_Big))) isIntersect = 1; // 포개어져 있는 경우
        else isIntersect = 0; // 그렇지 않고 일직선상에 있는 경우
    } else {
        isIntersect = L1LineL2Point <= 0 && L2LineL1Point <= 0;
    }

    printf("%d", isIntersect);

    return 0;
}