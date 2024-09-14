#include <stdio.h>
#include <stdlib.h>

int N, **space;
int sharkSize = 2;

struct rc {
    int r, c;
} *queue;
int l, r;

void push(struct rc target) {
    queue[r++] = target;
}

struct rc front() {
    return queue[l];
}

void pop() {
    l++;
}

int size() {
    return r - l;
}

_Bool empty() {
    return l == r;
}

void clear() {
    l = r = 0;
}

// BFS
struct rc findClosesetFish(struct rc shark, int *seconds) {
    int dx[8] = {-1, 0, 0, 1}, dy[8] = {0, -1, 1, 0};
    _Bool v[20][20] = {};
    clear();

    int searchSeconds = 0;
    v[shark.r][shark.c] = 1;
    push(shark);

    while (!empty()) {
        searchSeconds++;
        int minR = 0x7fffffff, minC = 0x7fffffff; // 주기 한번 돌 때 위, 왼족, 오른쪽, 아래 우선순위

        int qsize = size();
        while (qsize--) {
            struct rc cur = front();
            pop();

            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dx[i];
                int nc = cur.c + dy[i];

                if (0 <= nr && nr < N && 0 <= nc && nc < N && !v[nr][nc]) {
                    if (space[nr][nc] == 0 || space[nr][nc] == sharkSize) {
                        v[nr][nc] = 1;
                        push((struct rc){nr, nc});
                    } else if (space[nr][nc] < sharkSize) {
                        if (nr < minR || (nr == minR && nc < minC) || (minR == 0x7fffffff && nc < minC)) {
                            minR = nr;
                            minC = nc;
                        }
                    }
                }
            }
        }
        if (minR < 0x7fffffff) {
            (*seconds) += searchSeconds;
            return (struct rc){minR, minC};
        }
    }
    return (struct rc){-1, -1};
}

int eatFish(struct rc init) {
    int seconds = 0, fishCnt = 0;
    struct rc shark = init, closestFish;

    while ((closestFish = findClosesetFish(shark, &seconds)).r != -1) {
        if (++fishCnt == sharkSize) sharkSize++, fishCnt = 0;

        space[closestFish.r][closestFish.c] = 0;

        shark = closestFish;

        /* printf("%d %d\n", sharkSize, seconds);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", space[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
        putchar('\n'); */
    }

    return seconds;
}

int main() {
    scanf("%d", &N);

    space = (int **)malloc(8 * N);
    queue = (struct rc *)malloc(sizeof(struct rc) * N*N);

    struct rc initShark;

    for (int i = 0; i < N; i++) {
        space[i] = (int *)malloc(4 * N);
        for (int j = 0; j < N; j++) {
            scanf("%d", space[i]+j);
            if (space[i][j] == 9) {
                initShark = (struct rc){i, j};
                space[i][j] = 0;
            }
        }
    }

    printf("%d", eatFish(initShark));

    for (int i = 0; i < N; i++) free(space[i]);
    free(space);
    free(queue);

    return 0;
}