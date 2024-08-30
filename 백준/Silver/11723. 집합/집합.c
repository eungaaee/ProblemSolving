#include <malloc.h>
#include <stdio.h>
int s = 0;
void add(int op) {
    s = s | (1 << op);
}
void rm(int op) {
    s = s & ~(1 << op);
}
void check(int op) {
    printf("%d\n", (s & (1 << op)) > 0);
}
void toggle(int op) {
    s = s ^ (1 << op);
}
void all() {
    s = -1;
}
void empty() {
    s = 0;
}
int main() {
    int m, op2;
    char op1[7];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", op1);
        if (*op1 == 'a' && *(op1+1) == 'd') {
            scanf("%d", &op2);
            add(op2);
        } else if (*op1 == 'r') {
            scanf("%d", &op2);
            rm(op2);
        } else if (*op1 == 'c') {
            scanf("%d", &op2);
            check(op2);
        } else if (*op1 == 't') {
            scanf("%d", &op2);
            toggle(op2);
        } else if (*op1 == 'a' && *(op1+1) == 'l') {
            all();
        } else {
            empty();
        }
    }
}