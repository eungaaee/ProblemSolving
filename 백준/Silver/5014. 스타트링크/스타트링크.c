#include <stdio.h>

int F, S, G, U, D, depth;
int queue[1000000], lp, rp;

void push(int x) { queue[rp++] = x; }

void pop() { lp++; }

int front() { return queue[lp]; }

int size() { return rp-lp; }

_Bool empty() { return lp == rp; }

_Bool BFS() {
    int cur, nxt, d[2] = {U, -D}, qsize;
    _Bool v[1000001] = {};

    if (S == G) return 1;
    push(S);
    v[S] = 1;
    
    while (!empty()) {
        depth++;
        qsize = size();
        for (int c = 0; c < qsize; c++) {
            cur = front();
            pop();

            for (int i = 0; i < 2; i++) {
                nxt = cur+d[i];
                if (nxt < 1 || nxt > F) continue;
                else if (nxt == G) return 1;
                
                if (!v[nxt]) {
                    v[nxt] = 1;
                    push(nxt);
                }
            }
        }
    }

    return 0;
}

int main() {
    scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);

    if (BFS()) printf("%d", depth);
    else printf("use the stairs");

    return 0;
}