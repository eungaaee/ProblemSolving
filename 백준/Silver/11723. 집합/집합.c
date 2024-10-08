#include <stdio.h>

int S; // (1 << 21) < INT_MAX

void add(int x) { S |= (1 << x); }

void rm(int x) { S &= ~(1 << x); }

void check(int x) { printf("%d\n", (S & (1 << x)) > 0); }

void toggle(int x) { S ^= (1 << x); }

void all() { S = (1 << 21) - 1; } // 1000..0000 - 1 = 0111..1111

void empty() { S = 0; }

int main() {
    int M;
    scanf("%d", &M);

    char op[7];
    int x;
    
    while (M--) {
        scanf("%s", op);

        switch (op[1]) {
            case 'd': scanf("%d", &x); add(x); break;
            case 'e': scanf("%d", &x); rm(x); break;
            case 'h': scanf("%d", &x); check(x); break;
            case 'o': scanf("%d", &x); toggle(x); break;
            case 'l': all(); break;
            case 'm': empty(); break;
        }
    }

    return 0;
}