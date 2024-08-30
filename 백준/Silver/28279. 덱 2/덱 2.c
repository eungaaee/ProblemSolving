#include <stdio.h>

int deq[2000000], f = 999999, b = 1000000;

static inline _Bool empty() {
    return !(b-f-1);
}

static inline void pushfront(int n) {
    deq[f--] = n;
}

static inline void pushback(int n) {
    deq[b++] = n;
}

static inline int popfront() {
    if (empty()) return -1;
    return deq[++f];
}

static inline int popback() {
    if (empty()) return -1;
    return deq[--b];
}

static inline int size() {
    return b-f-1;
}

static inline int front() {
    if (empty()) return -1;
    return deq[f+1];
}

static inline int back() {
    if (empty()) return -1;
    return deq[b-1];
}

int main() {
    int N, c, x;
    scanf("%d", &N);
    for (register int i = 0; i < N; i++) {
        scanf("%d", &c);
        if (c == 1) {
            scanf("%d", &x);
            pushfront(x);
        } else if (c == 2) {
            scanf("%d", &x);
            pushback(x);
        } else if (c == 3) printf("%d\n", popfront());
        else if (c == 4) printf("%d\n", popback());
        else if (c == 5) printf("%d\n", size());
        else if (c == 6) printf("%d\n", empty());
        else if (c == 7) printf("%d\n", front());
        else if (c == 8) printf("%d\n", back());
    }
    return 0;
}