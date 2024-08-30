#include <malloc.h>
#include <stdio.h>
#include <string.h>
int main() {
    int n, *stack, t, p;
    char command[6];
    scanf("%d", &n);
    stack = (int*)malloc(sizeof(int) * n);
    p = -1;
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        if (!strcmp(command, "push")) {
            scanf("%d", &t);
            p++;
            stack[p] = t;
        } else if (!strcmp(command, "pop")) {
            if (p > -1) {
                printf("%d\n", stack[p]);
                p--;
            } else {
                puts("-1");
            }
        } else if (!strcmp(command, "size")) {
            printf("%d\n", p + 1);
        } else if (!strcmp(command, "empty")) {
            printf("%d\n", p > -1 ? 0 : 1);
        } else if (!strcmp(command, "top")) {
            printf("%d\n", p > -1 ? stack[p] : -1);
        }
    }
    free(stack);
    return 0;
}