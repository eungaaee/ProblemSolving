#include <stdio.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    
    int r, c, d;
    scanf("%d%d%d", &r, &c, &d);

    int room[N][M]; // 0: 청소되지 않음, 1: 벽, -1: 청소됨
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", room[i]+j);
        }
    }

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    room[r][c] = -1;
    int count = 1;

    while (1) {
        _Bool is_cleanable = 0;

        for (int i = 0; i < 4; i++) {
            d = (d+3) % 4; // 반시계
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                if (room[nr][nc] == 0) {
                    room[nr][nc] = -1;
                    count++;

                    r = nr, c = nc;
                    is_cleanable = 1;
                    break;
                }
            }
        }

        if (!is_cleanable) { // 네 방향 중 청소되지 않은 빈 칸이 없는 경우
            r -= dr[d], c -= dc[d]; // 후진
            if (room[r][c] == 1) break; // 벽 때문에 후진할 수 없으면 그만하기
        }
    }

    printf("%d", count);

    return 0;
}