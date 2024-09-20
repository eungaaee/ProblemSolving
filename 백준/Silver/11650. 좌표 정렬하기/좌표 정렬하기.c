#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} coordinate;

int compare(const void *a, const void *b) {
    if (((coordinate *)a)->x == ((coordinate *)b)->x)
        return ((coordinate *)a)->y - ((coordinate *)b)->y;
    else
        return ((coordinate *)a)->x - ((coordinate *)b)->x;
}

int main() {
    int N;
    coordinate *carr;
    scanf("%d", &N);

    carr = (coordinate *)malloc(sizeof(coordinate) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d%d", &carr[i].x, &carr[i].y);
    }

    qsort(carr, N, sizeof(coordinate), compare);
    
    for (int i = 0; i < N; i++) printf("%d %d\n", carr[i].x, carr[i].y);

    free(carr);

    return 0;
}