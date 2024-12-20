#include <stdio.h>
#define abs(n) ((n) > 0 ? (n) : -(n))

int size;
_Bool board[10][10]; // i, j >= 0
_Bool pos_used[21], neg_used[21]; // y=x+i, y=-x+i 대각선이 사용되었는지, i >= 1
int maximum_amount;

void backtrack(int idx, int placed) {
    if (idx >= 2*size) { // 대각선 번호의 최대값인 2*n에 도달했다면
        if (placed > maximum_amount) maximum_amount = placed;
        return;
    }

    _Bool is_placeable = 0;

    for (int i = 1; i <= size - abs(size-idx); i++) { // idx번째 대각선의 i번째 칸
        int r, c;
        if (idx <= size) r = idx-i, c = i-1;
        else r = size-i, c = idx-size + i-1;

        if (board[r][c] & !pos_used[idx] & !neg_used[size + r-c]) {
            if (!is_placeable) is_placeable = 1;

            pos_used[idx] = neg_used[size + r-c] = 1;
            backtrack(idx+1, placed+1);
            pos_used[idx] = neg_used[size + r-c] = 0;
        }
    }
    if (!is_placeable) backtrack(idx+1, placed);
}

int main() {
    scanf("%d", &size);

    int t_f;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &t_f);
            board[i][j] = t_f; // _Bool 자료형을 %d로 입력 받으면 제출했을 때만 틀림. 왜 그러지 근데
        }
    }

    backtrack(1, 0);
    printf("%d", maximum_amount);

    return 0;
}