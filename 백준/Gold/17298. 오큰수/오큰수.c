#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i, n;
} in;

in *stack;
int ptr;

void push(int i, int n) {
    stack[ptr++] = (in){i, n};
}

void pop() {
    ptr--;
}

in top() {
    return stack[ptr-1];
}

_Bool empty() {
    return !ptr;
}

int main() {
    int N;
    scanf("%d", &N);

    stack = (in *)malloc(N * sizeof(in));
    int *NGE = (int *)malloc(N*4 + 4);

    for (int i = 1, A; i <= N; i++) {
        scanf("%d", &A);

        // 스택이 비어있을 때 push and continue
        if (empty()) {
            push(i, A);
            continue;
        }

        // 이전에 나왔던 값들 중 A보다 작은 것들의 NGE를 A로 설정
        while (!empty() && A > top().n) {
            NGE[top().i] = A;
            pop();
        }

        push(i, A);
    }

    // 스택에 남아있는 값들은 NGE가 없는 값들
    while(!empty()) {
        NGE[top().i] = -1;
        pop();
    }

    for (int i = 1; i <= N; i++) printf("%d ", NGE[i]);

    free(stack);
    free(NGE);

    return 0;
}