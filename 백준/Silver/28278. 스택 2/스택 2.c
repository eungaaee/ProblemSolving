#include <stdio.h>

int stack[1000000], p=0;
static inline void push(int n) {
    stack[p++] = n;
}

static inline int pop() {
    if (p == 0) return -1;
    return stack[--p];
}

static inline int size() {
    return p;
}

static inline _Bool empty() {
    return !p;
}

static inline int top() {
    if (p == 0) return -1;
    return stack[p-1];
}

int main() {
    int N;
    scanf("%d", &N);

    int cmd, x;
    for (register int i = 0; i < N; ++i) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d", &x);
            push(x);
        } else if (cmd == 2) printf("%d\n", pop());
        else if (cmd == 3) printf("%d\n", size());
        else if (cmd == 4) printf("%d\n", empty());
        else if (cmd == 5) printf("%d\n", top());
    }
    return 0;
}