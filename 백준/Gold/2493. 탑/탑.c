#include <stdio.h>
#include <stdlib.h>

struct ih {
    int initIdx;
    int height;
} *stack;
int topIdx;

void push(struct ih x) { stack[topIdx++] = x; }
void pop() { topIdx--; }
struct ih top() { return stack[topIdx-1]; }
_Bool empty() { return !topIdx; }

int main() {
    int N;
    scanf("%d", &N);

    int *tower = (int *)malloc(N*4);
    int *recieve = (int *)calloc(N, 4);
    stack = (struct ih *)malloc(N*sizeof(struct ih));

    for (int i = 0; i < N; i++) scanf("%d", tower+i);

    for (int i = N-1; i >= 0; i--) {
        int cur = tower[i];
        while (!empty() && top().height < cur) {
            recieve[top().initIdx] = i+1;
            pop();
        }
        push((struct ih){i, cur});
    }

    for (int i = 0; i < N; i++) printf("%d ", recieve[i]);

    free(tower);
    free(stack);
    free(recieve);

    return 0;
}