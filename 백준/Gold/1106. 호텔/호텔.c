#include <stdio.h>
#define MAX_COST 100000 // 1000명 * 100원
#define max(a, b) (a > b ? a : b)

int C, N;
struct {
    unsigned int cost : 7;
    unsigned int value : 7;
} city[21];

void knapsack() {
    int dp[MAX_COST+1] = {};

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= MAX_COST; j++) {
            if (city[i].cost > j) continue;

            if (dp[j-city[i].cost] + city[i].value > dp[j])
                dp[j] = dp[j-city[i].cost] + city[i].value;
        }
    }

    for (int i = 0; i <= MAX_COST; i++) {
        if (dp[i] >= C) {
            printf("%d", i);
            break;
        }
    }
}

int main() {
    scanf("%d%d", &C, &N);
    for (int i = 1; i <= N; i++) {
        int c, v;
        scanf("%d%d", &c, &v);
        city[i] = (typeof(city[i])){c, v}; // typeof는 GCC 확장 문법에 해당하는 매크로 함수
    }

    knapsack();

    return 0;
}