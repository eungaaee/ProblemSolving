#include <stdio.h>

int N, M, city[50][50], store[13][3], storeCnt, minCityChickenDist = 0x7fffffff; // store[i] = (r, c, selected)

static inline int abs(int n) { return n < 0 ? -n : n; }

int getDistance() {
    int cityChickenDist = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (city[i][j] == 1) {
                int minHouseChickenDist = 0x7fffffff;
                for (int k = 0; k < storeCnt; k++) {
                    if (store[k][2]) {
                        int houseChickenDist = abs(i-store[k][0]) + abs(j-store[k][1]);
                        if (houseChickenDist < minHouseChickenDist) minHouseChickenDist = houseChickenDist;
                    }
                }
                cityChickenDist += minHouseChickenDist;
            }
        }
    }

    if (cityChickenDist < minCityChickenDist) minCityChickenDist = cityChickenDist;
}

void selectStore(int idx, int cnt) {
    if (cnt == M) {
        getDistance();
        return;
    }

    for (int i = idx; i < storeCnt; i++) {
        store[i][2] = 1;
        selectStore(i+1, cnt+1);
        store[i][2] = 0;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &city[i][j]);
            if (city[i][j] == 2) {
                store[storeCnt][0] = i;
                store[storeCnt][1] = j;
                storeCnt++;
            }
        }
    }

    selectStore(0, 0);

    printf("%d", minCityChickenDist);

    return 0;
}