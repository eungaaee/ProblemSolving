#include <stdio.h>

enum {EMPTY, APPLE, SNAKE};
enum RDLU {RIGHT, DOWN, LEFT, UP};

struct xc {
    int x;
    char c;
};

struct rc {
    int r, c;
};

int main() {
    int N, K;
    scanf("%d%d", &N, &K);

    int board[101][101] = {};

    for (int i = 0; i < K; i++) {
        int r, c;
        scanf("%d%d", &r, &c);
        board[r][c] = APPLE;
    }

    int L;
    scanf("%d", &L);

    struct xc turn[100] = {};
    int t_front = 0, t_back = 0;

    for (int i = 0; i < L; i++) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        turn[t_back++] = (struct xc){x, c};
    }

    struct rc snake[10000];
    int s_front = 0, s_back = 0;

    enum RDLU direction = RIGHT;
    board[1][1] = SNAKE;
    snake[s_back++] = (struct rc){1, 1};

    int t;
    for (t = 1; ; t++) {
        int head_r = snake[s_back-1].r;
        int head_c = snake[s_back-1].c;

        if (direction == LEFT) head_c--;
        else if (direction == RIGHT) head_c++;
        else if (direction == UP) head_r--;
        else if (direction == DOWN) head_r++;

        if (head_r < 1 || head_r > N || head_c < 1 || head_c > N) break;
        else if (board[head_r][head_c] == SNAKE) break;

        if (board[head_r][head_c] != APPLE) { // APPLE이면 꼬리를 줄이지 않고 넘어가기
            board[snake[s_front].r][snake[s_front].c] = EMPTY;
            s_front++;
        }

        board[head_r][head_c] = SNAKE;
        snake[s_back++] = (struct rc){head_r, head_c};

        if (t_front < t_back && turn[t_front].x == t) {
            /* if (turn[t_front].c == 'L') {
                direction--;
                if (direction < 0) direction = 3;
            } else {
                direction++;
                if (direction > 3) direction = 0;
            } */
            if (turn[t_front].c == 'L') direction = (direction - 1 + 4) % 4;
            else direction = (direction + 1) % 4;

            t_front++;
        }
    }

    printf("%d", t);

    return 0;
}