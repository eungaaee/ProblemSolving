#include <stdio.h>

enum office_info {EMPTY, ONE, TWO_STRAIGHT, TWO_CURVE, THREE, FOUR, WALL, WATCHING};
enum RULD {R, U, L, D};

struct rc {
    int r, c;
};

int N, M;
enum office_info office[8][8];

struct rc cctv[8];
int cctv_cnt;

int min_blind_spot = 1e9;

void set_cctv(struct rc target_cctv, enum RULD direction, _Bool on_off) {
    static int d[4] = {0, -1, 0, 1}; // RULD
    int dr = d[direction], dc = d[3-direction];

    while (0 <= target_cctv.r + dr && target_cctv.r + dr < N && 0 <= target_cctv.c + dc && target_cctv.c + dc < M && office[target_cctv.r + dr][target_cctv.c + dc] != WALL) {
        target_cctv.r += dr;
        target_cctv.c += dc;

        if (on_off == 1) {
            if (office[target_cctv.r][target_cctv.c] == EMPTY)
                office[target_cctv.r][target_cctv.c] = WATCHING;
            else if (office[target_cctv.r][target_cctv.c] >= WATCHING)
                office[target_cctv.r][target_cctv.c]++; // 감시하고 있는 CCTV의 개수를 증가
        } else if (on_off == 0) {
            if (office[target_cctv.r][target_cctv.c] == WATCHING)
                office[target_cctv.r][target_cctv.c] = EMPTY;
            else if (office[target_cctv.r][target_cctv.c] > WATCHING)
                office[target_cctv.r][target_cctv.c]--; // 두 개 이상이 보고 있는데 EMPTY로 바꿔버리면 안 됨
        }
    }
}

void backtrack(int cctv_idx) {
    if (cctv_idx >= cctv_cnt) {
        int blind_spot = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (office[i][j] == EMPTY) blind_spot++;
            }
        }
        if (blind_spot < min_blind_spot) min_blind_spot = blind_spot;
        
        return;
    }

    struct rc cur_cctv = cctv[cctv_idx];

    switch (office[cur_cctv.r][cur_cctv.c]) {
        case ONE: // 한 방향
            for (enum RULD i = R; i <= D; i++) {
                set_cctv(cur_cctv, i, 1);
                backtrack(cctv_idx+1);
                set_cctv(cur_cctv, i, 0);
            }
            break;
        case TWO_STRAIGHT: // 직선
            for (enum RULD i = R; i <= U; i++) {
                set_cctv(cur_cctv, i, 1);
                set_cctv(cur_cctv, i+2, 1);
                backtrack(cctv_idx+1);
                set_cctv(cur_cctv, i, 0);
                set_cctv(cur_cctv, i+2, 0);
            }
            break;
        case TWO_CURVE: // 직각
            for (enum RULD i = R; i <= D; i++) {
                set_cctv(cur_cctv, i, 1);
                set_cctv(cur_cctv, (i+1) % 4, 1);
                backtrack(cctv_idx+1);
                set_cctv(cur_cctv, i, 0);
                set_cctv(cur_cctv, (i+1) % 4, 0);
            }
            break;
        case THREE: // 세 방향
            for (enum RULD i = R; i <= D; i++) {
                set_cctv(cur_cctv, i, 1);
                set_cctv(cur_cctv, (i+1) % 4, 1);
                set_cctv(cur_cctv, (i+2) % 4, 1);
                backtrack(cctv_idx+1);
                set_cctv(cur_cctv, i, 0);
                set_cctv(cur_cctv, (i+1) % 4, 0);
                set_cctv(cur_cctv, (i+2) % 4, 0);
            }
            break;
        case FOUR: // 네 방향
            for (enum RULD i = R; i <= D; i++) set_cctv(cur_cctv, i, 1);
            backtrack(cctv_idx+1);
            for (enum RULD i = R; i <= D; i++) set_cctv(cur_cctv, i, 0);
            break;
    }
}

int main() {
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", office[i] + j);
            if (ONE <= office[i][j] && office[i][j] <= FOUR)
                cctv[cctv_cnt++] = (struct rc){i, j};
        }
    }

    backtrack(0);
    printf("%d", min_blind_spot);

    return 0;
}