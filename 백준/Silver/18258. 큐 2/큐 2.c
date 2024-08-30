#include <stdio.h>

int queue[2000000], l = 0, r = 0;

static inline _Bool empty();

static inline void push(int n) {
    queue[r++] = n;
}

static inline int pop() {
    if (empty()) return -1;
    return queue[l++];
}

static inline int size() {
    return r-l;
}

static inline _Bool empty() {
    return !(r-l);
}

static inline int front() {
    if (empty()) return -1;
    return queue[l];
}

static inline int back() {
    if (empty()) return -1;
    return queue[r-1];
}

int main() {
    int N;
    scanf("%d", &N);

    char cmd[6];
    int num;
    for (register int i = 0; i < N; ++i) {
        scanf("%s", cmd);
        if (cmd[1] == 'u') {
            scanf("%d", &num);
            push(num);
        } else if (cmd[1] == 'o') printf("%d\n", pop());
        else if (cmd[1] == 'i') printf("%d\n", size());
        else if (cmd[1] == 'm') printf("%d\n", empty());
        else if (cmd[1] == 'r') printf("%d\n", front());
        else if (cmd[1] == 'a') printf("%d\n", back());
    }
    return 0;
}